// This file contains the definitions of the functions of Maze class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "Maze.h"

using namespace std;

// This is the constructor which takes in the length and the width of the maze to be constructed.
Maze::Maze(int len, int width){
	srand(time(NULL));
	if(len < 3)
		len = 3;
	if(width < 3)
		width = 3;
	set = new Disjoint_set(len * width);
	graph = new vector<node>(len * width);
	while(set->get_num_of_sets() != 1){
		int num = rand() % (len * width);
		int up = num - len;
		int down = num + len;
		int left = num - 1;
		int right = num + 1;
		if(num % len == 0)
			left = -1;
		else if((num + 1) % len == 0)
			right = -1;
		int choose = rand() % 3;
		if(choose == 0 && up >= 0 && set->find_set(num) != set->find_set(up)){
			set->Union(num, up);
			(*graph)[num].adjacent_vertices.push_back(up);
			(*graph)[up].adjacent_vertices.push_back(num);
		}
		else if(choose == 1 && (down < (len * width)) && set->find_set(num) != set->find_set(down)){
			set->Union(num, down);
			(*graph)[num].adjacent_vertices.push_back(down);
			(*graph)[down].adjacent_vertices.push_back(num);
		}
		else if(choose == 2 && left > 0 && set->find_set(num) != set->find_set(left)){
			set->Union(num, left);
			(*graph)[num].adjacent_vertices.push_back(left);
			(*graph)[left].adjacent_vertices.push_back(num);
		}
		else if(choose == 3 && right > 0){
			set->Union(num, right);
			(*graph)[num].adjacent_vertices.push_back(right);
			(*graph)[right].adjacent_vertices.push_back(num);
		}
	}
	int i = 0;
	while(i < graph->size()){
		(*graph)[i].known = false;
		(*graph)[i].distance = INT_MAX;
		++i;
	}
	path = "";
	length = len;
	breadth = width;
}

// This is the copy constructor which takes another object and constructs a new object by copying the contents of the object 
// taken as argument.
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

// This function takes in a vector and a number and returns whether the number is present in the vector or not.
bool Maze::contains(vector<int> array, int element){
	int i = 0;
	while(i < array.size()){
		if(array[i] == element)
			return true;
		++i;
	}
	return false;
}

// This function prints the maze.
void Maze::print(){
	cout << "      ";
	int i = 1;
	while(i < length){
		cout << "____ ";
		++i;
	}
	i = 0;
	while(i < breadth){
		int j = length * i;
		while(j < length * (i+1)){
			int left = j-1;
			int right = j+1;
			int down = j + length;
			if(j == length * i && !contains((*graph)[j].adjacent_vertices, left))
				cout << endl << "|";
			if(j != (length*breadth -1) && !contains((*graph)[j].adjacent_vertices, down))
				cout << "____";
			else
				cout << "    ";
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

}

// This is the destructor which frees the memory dynamicaly allocated while constructing the object.
Maze::~Maze(){
	delete set;
	delete graph;
}