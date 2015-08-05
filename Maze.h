// This is the declaration of the maze class

#include <iostream>
#include <string>
#include "Disjoint_set.h"

#ifndef MAZE_H
#define MAZE_H

using namespace std;

struct node{
	vector<int> adjacent_vertices;
	bool known;
	int distance;
	int path;
};

class Maze{
private:
	Disjoint_set* set;
	vector<node>* graph;
	string path;
public:
	Maze(int, int);
	Maze(const Maze&);
	void print();
	void shortest_path();
	void print_path();
	bool is_correct(string);
	void run();
	~Maze();
};

#endif