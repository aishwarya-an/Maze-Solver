// This is the declaration of the Disjoint_set class

#include <iostream>
#include <vector>

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

using namespace std;

struct cell{
	int index;
	int rank;
	int representative;
	vector<int> neighbours;
};

class Disjoint_set{
private:
	vector<cell>* set;
	int elements;
	int num_of_sets;
public:
	Disjoint_set(int);
	Disjoint_set(const Disjoint_set&);
	int find_set(int);
	const vector<cell>* get_set() const;
	int get_size() const;
	int get_num_of_sets() const;
	void Union(int, int);
	~Disjoint_set();
};

#endif