// This is the definition of the functions of Disjoint_set class

#include <iostream>
#include "Disjoint_set.h"

using namespace std;

// This is the constructor which takes in the number of elements in the set to be constructed.
Disjoint_set::Disjoint_set(int size){
	
}


// This is the copy constructor which takes in another object and constructs a new object by copying the contents of the object
// passed as argument.
Disjoint_set::Disjoint_set(const Disjoint_set &another){
	
}


// This funtion takes in a cell in the disjoint set and returns the index of its representative. It also uses path compression i.e
// it changes the representative of all the elements in the path to the representative of the set. 
int Disjoint_set::find_set(int Node){
	return 0;
} 

// This function returns the number of elements in the set.
int Disjoint_set::get_size() const{
	return 0;
}

// This function returns the pointer to the vector which contains all the elements. Since, the vector returned is a private member
// of the class it returns as a const object.
const vector<cell>* Disjoint_set::get_set() const{
	return new vector<cell>();
}

// This function returns the number of sets in the object calling this function. 
int Disjoint_set::get_num_of_sets() const{
	return 0;
}

// This function takes in two cells and combines the two separate sets in which they are present. If they are present in the same 
// set, then this function does not do anything. 
void Disjoint_set::Union(int Node1, int Node2){
	
}

// This is the destructor which frees the memory dynamically allocated by the constructor.
Disjoint_set::~Disjoint_set(){
	
}