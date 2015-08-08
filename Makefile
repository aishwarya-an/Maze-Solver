CXX = g++

# The name of the executable is maze.
maze: Maze-solver.cpp Maze.o Disjoint_set.o
	$(CXX) -o maze Maze-solver.cpp Maze.o Disjoint_set.o

Maze.o: Maze.cpp
	$(CXX) -c Maze.cpp

Disjoint_set.o: Disjoint_set.cpp
	$(CXX) -c Disjoint_set.cpp

clean:
	rm -f *.o maze