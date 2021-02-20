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
	int start_h_n = 0;
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

		curr_node = nodes.front();
		pop_heap(nodes.begin(), nodes.end(), Node_rank_greater_than());		//node = REMOVE-FRONT(nodes) 
		nodes.pop_back();
		curr_distance = curr_node.current_board.get_board_total_distance();
		if (curr_distance == 0) {											//if problem.GOAL-TEST(node.STATE) succeeds then return node
			cout << "Goal!!!!" << endl;
			cout << endl;
			cout << "This search algorithm expanded a total of " << nodes_expanded << " nodes." << endl;
			cout << "The max number of nodes in the queue at any point in time was " << max_heap_size << "." << endl;
			cout << "The depth of the goal node was " << curr_node.g_n << "." << endl;
			return curr_node;
		}
		vector<Node> nodes_from_expansion = expand(curr_node);
		nodes = (*queueing_function)(nodes, nodes_from_expansion);				//nodes = QUEUEING - FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
	
	}
	// Goal_TEST
}
vector<Node> uniform_cost(vector<Node> nodes,vector<Node> nodes_from_expansion) {

	while (!nodes_from_expansion.empty()) {
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
		int new_h_n = nodes_from_expansion.back().current_board.get_num_incorrect_tiles();
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
	cout << "Type 1 to use a default puzzle, or 2 to enter your own puzzle." << endl;
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
		solution = general_search(Board(board_values), queueing_function);
	}


	return -1;
}