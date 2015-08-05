// This file contains the definitions of the functions of Maze class

#include <iostream>
#include "Maze.h"

using namespace std;

// This is the constructor which takes in the length and the breadth of the maze to be constructed.
Maze::Maze(int length, int breadth){

}

// This is the copy constructor which takes another object and constructs a new object by copying the contents of the object 
// taken as argument.
Maze::Maze(const Maze &another_maze){

}

// This function prints the maze.
void Maze::print(){

}

// This function finds the shortest path from the entrance of the maze to the exit of the maze. It uses the shortest path 
// algorithm. It also stores the path in a private member.
void Maze::shortest_path(){

}

// This function prints the shortest path from the entrance of the maze to the exit of the maze. Te shortest path is stored in
// a private member.
void Maze::print_path(){

}

// This function takes in a string and returns whether it is the shortest path from the entrance to the exit of the maze.
bool Maze::is_correct(string answer){
	return true;
}

// This function first prints the maze for the user using the print() function. It then finds the shortest path using the 
// shortest_path() function. It then takes input of the answer(of the path) from the user and gives the correct answer incase of 
// wrong answer from the user. Its running time is O(nm) where n and m are the length and the breadth of the maze respectively. 
void Maze::run(){

}

// This is the destructor which frees the memory dynamicaly allocated while constructing the object.
Maze::~Maze(){

}