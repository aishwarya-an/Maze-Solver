// This file contains the definitions of the functions of Maze class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <queue>
#include "Maze.h"

using namespace std;

// This is the constructor which takes in the length and the width of the maze to be constructed. Its running time is O(nm)
// where n and m are the length and breadth of the maze. To construct the maze, there can be atmost nm - 1 calls made to 
// union() function of the disjoint set. Since, the disjoint set uses the heuristics 'union by rank' and 'path compression',
// the running time will be O(m) where m is the total number of calls made. Then, the initializing the graph takes O(nm) time. 
// Therefore, totally the running time is O(nm).
Maze::Maze(int len, int width){
	srand(time(NULL));
	if(len < 5)
		len = 5;
	if(width < 5)
		width = 5;
	set = new Disjoint_set(len * width);
	graph = new vector<node>(len * width);
	// While there is only one set left.
	while(set->get_num_of_sets() != 1){
		// Taking a random cell in the maze.
		int num = rand() % (len * width);
		int up = num - len; 												// index of the cell above the current cell
		int down = num + len; 												// index of the cell below the current cell	
		int left = num - 1;													// index of the cell to the left of the current cell
		int right = num + 1; 												// index of the cell to the right of the current cell
		// If the current cell is in the leftmost boundary
		if(num % len == 0)
			left = -1;
		// If the current cell is in the rightmost boundary
		else if((num + 1) % len == 0)
			right = -1;
		// Getting a random number within 4 numbers to break one of the wall surrounding the current cell 
		int choose = rand() % 3;
		// Breaking the wall, if any above the current cell
		if(choose == 0 && up >= 0 && set->find_set(num) != set->find_set(up)){
			set->Union(num, up);
			(*graph)[num].adjacent_vertices.push_back(up);
			(*graph)[up].adjacent_vertices.push_back(num);
		}
		// Breaking the wall, if any below the current cell
		else if(choose == 1 && (down < (len * width)) && set->find_set(num) != set->find_set(down)){
			set->Union(num, down);
			(*graph)[num].adjacent_vertices.push_back(down);
			(*graph)[down].adjacent_vertices.push_back(num);
		}
		// Breaking the wall, if any to the left of the current cell
		else if(choose == 2 && left > 0 && set->find_set(num) != set->find_set(left)){
			set->Union(num, left);
			(*graph)[num].adjacent_vertices.push_back(left);
			(*graph)[left].adjacent_vertices.push_back(num);
		}
		// Breaking the wall, if any to the right of the current cell
		else if(choose == 3 && right > 0){
			set->Union(num, right);
			(*graph)[num].adjacent_vertices.push_back(right);
			(*graph)[right].adjacent_vertices.push_back(num);
		}
	}
	int i = 0;
	// Initializing the distance of each node from the first node to infinity i.e in this case INT_MAx
	while(i < graph->size())
		(*graph)[i++].distance = INT_MAX;
	path = "";
	length = len;
	breadth = width;
}


// This is the copy constructor which takes another object and constructs a new object by copying the contents of the object 
// taken as argument. Its running time is O(nm) where n and m are the length and the breadth of the other object.
Maze::Maze(const Maze &another_maze){
	set = new Disjoint_set(*another_maze.get_set());
	graph = new vector<node>(*another_maze.get_graph());
	path = another_maze.get_path();
	length = another_maze.get_length();
	breadth = another_maze.get_breadth();
}

// This function returns the disjoint set of the maze calling this function.
const Disjoint_set* Maze::get_set() const{
	return set;
}

// This function returns the vector containing the adjacency list of the nodes in the maze.
const vector<node>* Maze::get_graph() const{
	return graph;
}

// This function returns the string which is the shortest path from the entrance to the exit of the maze calling this function
string Maze::get_path() const{
	return path;
}

// This function returns the length of the maze.
int Maze::get_length() const{
	return length;
}

// This function returns the breadth of the maze.
int Maze::get_breadth() const{
	return breadth;
}

// This function takes in a vector and a number and returns whether the number is present in the vector or not. This is a
// private function called by the print() function to check whether a node has up or down or left or right walls present.
// Since, a node can have atmost 4 walls surrounding it, the running time of this function is O(1).
bool Maze::contains(vector<int> array, int element){
	int i = 0;
	while(i < array.size()){
		if(array[i] == element)
			return true;
		++i;
	}
	return false;
}

// This function prints the maze. Its running time is O(nm) where n and m are the length and the breadth of the maze 
// respectively. The adjacent vertices member of the structure node stores the index of the cells surrounding the node,
// such that there is no wall between the node and the nodes stored in the cell.
void Maze::print(){
	// Printing the top boundary of the maze.
	cout << "      ";
	int i = 1;
	while(i < length){
		cout << "____ ";
		++i;
	}
	// Printing all the walls of each row.
	i = 0; 																	// i represents the row
	while(i < breadth){
		int j = length * i;
		// j represents the current cell whose walls are to be printed. While j is the last cell in that row.
		while(j < length * (i+1)){
			int left = j-1;
			int right = j+1;
			int down = j + length;
			// If j is the first cell in that row, print | to its left
			if(j == length * i && !contains((*graph)[j].adjacent_vertices, left))
				cout << endl << "|";
			// If j is not the exit cell and it has a wall below, then print ___.
			if(j != (length*breadth -1) && !contains((*graph)[j].adjacent_vertices, down))
				cout << "____";
			// If there is no wall then give space.
			else
				cout << "    ";
			// If the cell has a right wall
			if(!contains((*graph)[j].adjacent_vertices, right))
				cout << "|";
			else
				cout << " ";
			++j;
		}
		++i;
	}
	cout << endl;
}

// This function finds the shortest path from the entrance of the maze to the exit of the maze. It uses the shortest path 
// algorithm. It also stores the path in a private member.
void Maze::shortest_path(){
	(*graph)[0].distance = 0;
	(*graph)[0].path = 0;
	queue<int> queue_of_nodes;
	queue_of_nodes.push(0);
	// Finding the shortest path from the entrance to the exit.
	while(!queue_of_nodes.empty()){
		int current = queue_of_nodes.front();
		queue_of_nodes.pop();
		int i = 0;
		while(i < (*graph)[current].adjacent_vertices.size()){
			int adj_vertex = (*graph)[current].adjacent_vertices[i];
			if((*graph)[adj_vertex].distance == INT_MAX){
				(*graph)[adj_vertex].distance = (*graph)[current].distance + 1;
				(*graph)[adj_vertex].path = current;
				queue_of_nodes.push((*graph)[current].adjacent_vertices[i]);
			}
			++i;
		}
	}
	// Storing the path from the entrnce to the exit.
	int i = (length * breadth) - 1;
	path = "";
	// Starting from the exit and finding the path backwards. Until the current cell is the frist cell the loop will run.
	// i.e Until the path is completed.
	while(i != 0){
		// If the previous cell in the path is to the left side of the current cell.
		if((*graph)[i].path == i - 1)
			path.insert(path.begin(), 'E');
		// If the previous cell in the path is to the right side of the current cell.
		else if((*graph)[i].path == i + 1)
			path.insert(path.begin(), 'W');
		// If the previous cell in the path is above the current cell.
		else if((*graph)[i].path == i - length)
			path.insert(path.begin(), 'S');
		// If the previous cell in the path is below the current cell.
		else
			path.insert(path.begin(), 'N');
		i = (*graph)[i].path;
	}
	// Inserting S at the beginning and at the end of the path string, since the user has to enter the first cell and exit 
	// from the last cell.
	path.insert(path.begin(), 'S');
	path.insert(path.end(), 'S');
}

// This function prints the shortest path from the entrance of the maze to the exit of the maze. The shortest path is stored in
// a private member.
void Maze::print_path(){
	cout << "The correct answer from the entrance to the exit is : " << endl << path << endl;
}

// This function takes in a string and returns whether it is the shortest path from the entrance to the exit of the maze.
bool Maze::is_correct(string answer){
	return path == answer;
}

// This function first prints the maze for the user using the print() function. It then finds the shortest path using the 
// shortest_path() function. It then takes input of the answer(of the path) from the user and gives the correct answer incase of 
// wrong answer from the user. Its running time is O(nm) where n and m are the length and the width of the maze respectively. 
void Maze::run(){
	print();
	shortest_path();
	cout << endl << "You need to find the shortest path from the entrance of the maze(i.e the top left corner) to the exit"
	<< "(i.e the right bottom corner)." << endl 
	<< "The path should be given in terms of N, S, W and E where N represents moving from "
	<< "the current cell to the above cell, S represents moving from the current cell to the below cell, E represents moving "
	<< "from the current cell to the right cell and W represents moving from the current cell to the left cell. "
	<< endl << "Please give the answer : " << endl;
	string answer;
	cin >> answer;
	if(is_correct(answer))
		cout << "Congratulations !!! You have given the right answer...." << endl << endl;
	else{
		cout << "Sorry...You have given the wrong answer..." << endl << endl;
		print_path();
	}
}

// This is the destructor which frees the memory dynamicaly allocated while constructing the object.
Maze::~Maze(){
	delete set;
	delete graph;
}