// This is a game which creates a maze for the player to find the shortest path from the entrance of the maze to the exit.

#include <iostream>
#include "Maze.h"

using namespace std;

int main(){
	cout << endl << "~~~~~~~~WELCOME TO THE GAME OF SOLVING A MAZE~~~~~~~~~~" << endl << "Choose any options(1 or 2 or 3) given" 
	<< " below to continue...." << endl << "1. Demo on how to play the game." << endl << "2. Play the game." << endl 
	<< "3. Exit." << endl << "Enter only the number of the option you choose  :  ";
	int option;
	cin >> option;
	do{
		switch(option){
			case 1: {
						cout << endl << "Welcome to the Demo mode" << endl 
						<< "Press 1 to start and 0 to exit from the demo mode : ";
						int num;
						cin >> num;
						if(num){
							cout << endl << "You need to first enter the specifications of the maze you want i.e the length and " 
							 << "breadth of the maze." << endl <<  "Then, the maze according to your specification is printed." 
							 << endl << endl << "Finally, give the shortest path from the entrance of the maze to the exit in terms of "
							 << "N, S, E, W(uppercase only) where N represents moving from the current cell to the above cell,"
							 << " S represents moving from the current cell to the below cell, E represents moving from the "
							 << "current cell to the right cell and W represents moving from the current cell to the left cell."
							 << endl << endl << "Now, see the demo where the maze is of 5 X 5 specification...." << endl;
						 	Maze* demo = new Maze(5, 5);
						 	demo->print();
						 	demo->shortest_path();
						 	demo->print_path();
						}
						cout << endl << "Press 1 to get demo, 2 to play again and 3 to exit from the game.....";
						cin >> option;
					}
					 break;
			case 2: {
						int length, breadth;
						cout << endl << "Please enter the specification of the maze you want..." << endl;
						cout << "Length of the maze (greater than 4) : ";
						cin >> length;
						cout << "Breadth of the maze (greater then 4) : ";
						cin >> breadth;
						cout << "This is your maze..." << endl;
						Maze* one = new Maze(length, breadth);
						one->run();
						cout << endl << "Press 1 to get demo, 2 to play again and 3 to exit from the game.....";
						cin >> option;
					}
					break;
			case 3: cout << endl << "Exiting the game. Thank you for playing the game. " << endl << endl;
					break;
			default: cout << endl << "There is no such option. Exiting the game...." << endl << endl;
			 		 break;
		}
	}while(option == 1 || option == 2);
	cout << endl << "Exiting the game. Thank you for playing the game. " << endl << endl;
	return 0;
}