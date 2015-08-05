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
	int length;
	int breadth;
	Disjoint_set* set;
	vector<node>* graph;
	string path;
	bool contains(vector<int>, int);
public:
	Maze(int, int);
	Maze(const Maze&);
	const Disjoint_set* get_set() const;
	const vector<node>* get_graph() const;
	string get_path() const;
	int get_length() const;
	int get_breadth() const;
	void print();
	void shortest_path();
	void print_path();
	bool is_correct(string);
	void run();
	~Maze();
};

#endif