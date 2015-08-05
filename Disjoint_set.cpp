// This is the definition of the functions of Disjoint_set class

#include <iostream>
#include "Disjoint_set.h"

using namespace std;

// This is the constructor which takes in the number of elements in the set to be constructed.
Disjoint_set::Disjoint_set(int size){
	set = new vector<cell>(size);
	int i = 0;
	while(i < size){
		(*set)[i].index = i;
		(*set)[i].rank = 0;
		(*set)[i].representative = i;
		++i;
	}
	elements = size;
	num_of_sets = size;
}


// This is the copy constructor which takes in another object and constructs a new object by copying the contents of the object
// passed as argument.
Disjoint_set::Disjoint_set(const Disjoint_set &another){
	set = new vector<cell>(another.get_size());
	const vector<cell>* set2 = another.get_set();
	int i = 0;
	while(i < set2->size()){
		(*set)[i].index = (*set2)[i].index;
		(*set)[i].rank = (*set2)[i].rank;
		(*set)[i].representative = (*set2)[i].representative;
		++i;
	}
	elements = another.get_size();
	num_of_sets = another.get_num_of_sets();
}


// This funtion takes in a cell in the disjoint set and returns the index of its representative. It also uses path compression i.e
// it changes the representative of all the elements in the path to the representative of the set. 
int Disjoint_set::find_set(int Node){
	if((*set)[Node].representative != Node)
		(*set)[Node].representative = find_set((*set)[Node].representative);
	return (*set)[Node].representative;
} 

// This function returns the number of elements in the set.
int Disjoint_set::get_size() const{
	return elements;
}

// This function returns the pointer to the vector which contains all the elements. Since, the vector returned is a private member
// of the class it returns as a const object.
const vector<cell>* Disjoint_set::get_set() const{
	return set;
}

// This function returns the number of sets in the object calling this function. 
int Disjoint_set::get_num_of_sets() const{
	return num_of_sets;
}

// This function takes in two cells and combines the two separate sets in which they are present. If they are present in the same 
// set, then this function does not do anything. 
void Disjoint_set::Union(int Node1, int Node2){
	int rep1 = find_set(Node1);
	int rep2 = find_set(Node2);
	if(rep1 != rep2){
		// If the height of rep1 is deeper then make the representative of rep2 as rep1.
		if((*set)[rep1].rank > (*set)[rep2].rank)
			(*set)[rep2].representative = rep1;
		// Else make the representative of rep2 as rep1.
		else{
			(*set)[rep1].representative = rep2;
			// If both are of the same height, then increase the height of rep2 by 1, since its child is now rep1.
			if((*set)[rep1].rank == (*set)[rep2].rank)
				++(*set)[rep2].rank;
		}
		// Decrease the number of sets by 1.
		--num_of_sets;
	}
}

// This is the destructor which frees the memory dynamically allocated by the constructor.
Disjoint_set::~Disjoint_set(){
	delete set;
}