#include "Board.h"
#include "Position.h"
#include "Node.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int nodes_expanded;
int max_heap_size = 0;
//used to compare 2 nodes in the tree
struct Node_rank_greater_than {
	bool operator()(Node const& a, Node const& b) const {
		return ((a.g_n + a.h_n) > (b.g_n + b.h_n));
	}
};


vector<Node> expand(Node n) {
	nodes_expanded++;
	Position blank_tile = n.current_board.get_blank();
	cout << endl;
	if (n.current_board.get_last_move() == NONE) {
		cout << "Expanding state" << endl;
	}
	else {
		cout << "The best state to expand with a g(n) = " << n.g_n << " and h(n) = " << n.h_n << " is..." << endl;
	}
	n.current_board.print_board();
	vector<Node> nodes_to_be_added_to_heap;
	Board board_copy_to_be_modified = n.current_board;
	Node tempNode = n;
	if (n.current_board.can_move(UP)) {
		board_copy_to_be_modified = n.current_board;
		board_copy_to_be_modified.move_up(blank_tile);
		tempNode = Node(n.g_n + 1, 0, board_copy_to_be_modified);
		nodes_to_be_added_to_heap.push_back(tempNode);
	}
	if (n.current_board.can_move(DOWN)) {
		board_copy_to_be_modified = n.current_board;
		board_copy_to_be_modified.move_down(blank_tile);
		tempNode = Node(n.g_n + 1, 0, board_copy_to_be_modified);
		nodes_to_be_added_to_heap.push_back(tempNode);
	}
	if (n.current_board.can_move(LEFT)) {
		board_copy_to_be_modified = n.current_board;
		board_copy_to_be_modified.move_left(blank_tile);
		tempNode = Node(n.g_n + 1, 0, board_copy_to_be_modified);
		nodes_to_be_added_to_heap.push_back(tempNode);
	}
	if (n.current_board.can_move(RIGHT)) {
		board_copy_to_be_modified = n.current_board;
		board_copy_to_be_modified.move_right(blank_tile);
		tempNode = Node(n.g_n + 1, 0, board_copy_to_be_modified);
		nodes_to_be_added_to_heap.push_back(tempNode);
	}
	return nodes_to_be_added_to_heap;
}

Node general_search(Board problem_initial_state, vector<Node> (*queueing_function)(vector<Node> my_heap, vector<Node> expand_result)) {
											//function general-search(problem, QUEUEING-FUNCTION)
	int start_g_n = 0;
	int start_h_n = problem_initial_state.get_board_total_distance();
	Node Initial_Node = Node(start_g_n, start_h_n, problem_initial_state);
	vector<Node> nodes;
	Node curr_node = Initial_Node;
	int curr_distance;
	nodes.push_back(Initial_Node);
	max_heap_size = 0;
	nodes_expanded = 0;
	make_heap(nodes.begin(), nodes.end(), Node_rank_greater_than());										// nodes = make_queue(make_node(problem.initial_state))
	while (true) {															// loop do
		if (nodes.empty()) {														//if EMPTY(nodes) then return "failure" 
			cout << "error, empty heap no solution found" << endl;
			return Node(-1, -1, problem_initial_state);
			//return an error node ex.Node(-1, -1, Board());
		}

		curr_node = nodes.back();
		pop_heap(nodes.begin(), nodes.end(), Node_rank_greater_than());		//node = REMOVE-FRONT(nodes) 
		nodes.pop_back();
		curr_distance = curr_node.current_board.get_board_total_distance();
		if (curr_distance == 0) {											//if problem.GOAL-TEST(node.STATE) succeeds then return node
			return curr_node;
		}
		nodes = (*queueing_function)(nodes, expand(curr_node));
																			//nodes = QUEUEING - FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
	}
	// Goal_TEST
}
vector<Node> uniform_cost(vector<Node> nodes,vector<Node> nodes_from_expansion) {

	while (!nodes_from_expansion.empty()) {
		int new_h_n = nodes_from_expansion.back().current_board.get_board_total_distance();
		nodes_from_expansion.back().h_n = 0;
		nodes.push_back(nodes_from_expansion.back());
		if (nodes.size() > max_heap_size) {
			max_heap_size = nodes.size();
		}
		nodes_from_expansion.pop_back();
		push_heap(nodes.begin(), nodes.end(), Node_rank_greater_than());
	}
	return nodes;
}
vector<Node> a_star_misplaced_tile(vector<Node> nodes, vector<Node> nodes_from_expansion) {

	while (!nodes_from_expansion.empty()) {
		int new_h_n = nodes_from_expansion.back().current_board.get_num_correct_tiles();
		nodes_from_expansion.back().h_n = new_h_n;
		nodes.push_back(nodes_from_expansion.back());
		if (nodes.size() > max_heap_size) {
			max_heap_size = nodes.size(); 
		}
		nodes_from_expansion.pop_back();
		push_heap(nodes.begin(), nodes.end(), Node_rank_greater_than());
	}
	return nodes;
}
vector<Node> a_star_manhattan_distance(vector<Node> nodes, vector<Node> nodes_from_expansion) {

	while (!nodes_from_expansion.empty()) {
		int new_h_n = nodes_from_expansion.back().current_board.get_board_total_distance();
		nodes_from_expansion.back().h_n = new_h_n;
		nodes.push_back(nodes_from_expansion.back());
		if (nodes.size() > max_heap_size) {
			max_heap_size = nodes.size(); 
		}
		nodes_from_expansion.pop_back();
		push_heap(nodes.begin(), nodes.end(), Node_rank_greater_than());
	}
	return nodes;
}


int main() {
	Board myBoard = Board(1, 1, 1, 1, 0, 1, 1, 1, 1);
	Board Board_if_move_up(0, 0, 0, 0, 0, 0, 0, 0, 0);
	Board Board_if_move_left(0, 0, 0, 0, 0, 0, 0, 0, 0);
	Board Board_if_move_down(0, 0, 0, 0, 0, 0, 0, 0, 0);
	Board Board_if_move_right(0, 0, 0, 0, 0, 0, 0, 0, 0);
	vector<Node> myheap;

	//for each iteration
	//if we are at the solution, stop here were done

	int dist_of_choice_up;  // option 1
	int dist_of_choice_left;  //option 2
	int dist_of_choice_down;  //option 3
	int dist_of_choice_right;  //option 4
	int choice = 0;
	Position blankTile;
	int previousChoice = -1;
	int board_values[WIDTH][HEIGHT];
	int board_distance_of_choice = -1;
	string input;
	int algorithm_choice;
	dist_of_choice_up = 9999;
	dist_of_choice_left = 9999;
	dist_of_choice_down = 9999;
	dist_of_choice_right = 9999;

	cout << "Welcome to Trevor Cappon's 8 Puzzle Solver" << endl;
	cout << "Type “1” to use a default puzzle, or “2” to enter your own puzzle." << endl;
	cout << "Enter your puzzle, use a zero to represent the blank" << endl;

	for (int row = 0; row < HEIGHT; row++) {
		cout << "Enter row " << row + 1 << " of the puzzle (use a space between numbers): " << endl;
		getline(cin, input);
		istringstream iss(input);
		for (int index = 0; index < WIDTH; index++) {
			iss >> board_values[index][row];
		}
	}

	cout << "Enter your choice of algorithm" << endl;
	cout << "1. Uniform Cost Search" << endl;
	cout << "2. A* with the Misplaced Tile heuristic" << endl;
	cout << "3. A* with the Manhattan distance heuristic" << endl;

	vector<Node> (*queueing_function)(vector<Node> my_heap, vector<Node> expand_result);
	Node solution = Node(0, 0, Board());
	while (cin >> algorithm_choice) {
		if (algorithm_choice == 1) {
			queueing_function = uniform_cost;
		}
		else if (algorithm_choice == 2) {
			queueing_function = a_star_misplaced_tile;
		}
		else if (algorithm_choice == 3) {
			queueing_function = a_star_manhattan_distance;
		}
		else {
			cout << "Please enter 1, 2, or 3" << endl;
		}
		solution = general_search(myBoard, queueing_function);
	}


	if ((blankTile.get_tile_x_value() > 0) && (previousChoice != 1)) {	//if blank tile is not on the left column, calc dist for moving left
		Board_if_move_left = myBoard;
		Board_if_move_left.move_left(blankTile);
		board_distance_of_choice = Board_if_move_left.get_board_total_distance();
		choice = 1;
	}
	if ((blankTile.get_tile_x_value() < 2) && (previousChoice != 2)) {	//if blank tile is not on the right column, calc dist for moving right
		Board_if_move_right = myBoard;
		Board_if_move_right.move_right(blankTile);
		dist_of_choice_right = Board_if_move_right.get_board_total_distance();
		if (dist_of_choice_right < board_distance_of_choice) {
			choice = 2;
			board_distance_of_choice = dist_of_choice_right;
		}
	}
	if ((blankTile.get_tile_y_value() > 0) && (previousChoice != 3)) {	//if blank tile is not on the top column, calc dist for moving up
		Board_if_move_up = myBoard;
		Board_if_move_up.move_up(blankTile);
		dist_of_choice_up = Board_if_move_up.get_board_total_distance();
		if (dist_of_choice_up < board_distance_of_choice) {
			choice = 3;
			board_distance_of_choice = dist_of_choice_up;
		}
	}
	if ((blankTile.get_tile_y_value() < 2) && (previousChoice != 4)) {	//if blank tile is not on the bottom column, calc dist for moving down
		Board_if_move_down = myBoard;
		Board_if_move_down.move_down(blankTile);
		dist_of_choice_down = Board_if_move_down.get_board_total_distance();
		if (dist_of_choice_down < board_distance_of_choice) {
			choice = 4;
			board_distance_of_choice = dist_of_choice_down;
		}
	}

	if (choice == 1) {
		myBoard.move_left(blankTile);
		blankTile.tile_update_left();
	}
	else if (choice == 2) {
		myBoard.move_right(blankTile);
		blankTile.tile_update_right();
	}
	else if (choice == 3) {
		myBoard.move_up(blankTile);
		blankTile.tile_update_up();
	}
	else if (choice == 4) {
		myBoard.move_down(blankTile);
		blankTile.tile_update_down();
	}

	previousChoice = choice;

	//if blank tile is at [1][1]
	//	Board_if_move_up = myBoard;
	//	Board_if_move_up.move_up(blankTile);
	//  Board_if_move_left = myBoard;
	//  Board_if_move_left.move_left(blankTile);
	//  Board_if_move_down = myBoard;
	//  Board_if_move_down.move_down(blankTile);
	//  Board_if_move_right = myBoard;
	//  Board_if_move_right.move_right(blankTile);

	//if blank tile ((x == 0 || x == 2) && (y == 0 || y == 2)    //blank tile is at a corner
	//  
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();

	blankTile = myBoard.move_down(blankTile);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();

	blankTile = myBoard.move_up(blankTile);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();

	blankTile = myBoard.move_right(blankTile);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();

	blankTile = myBoard.move_left(blankTile);
	myBoard.print_top_row();
	myBoard.print_mid_row();
	myBoard.print_bottom_row();
	return -1;
}