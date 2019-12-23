
#include "../src/SL_PriorityQueue.cpp"
#include "../src/LinkedSortedList.cpp"
#include "../src/implementation.cpp"									// Redblob games source code
#include <iostream>
#include <string>


/*===============================================================================
CLASS:             graphNode{};
DESCRIPTION:	   Meant to be a graph structure to demonanstrate A* Algorithm
NOTES:             Not used in code
STATUS:			   INCOMPLETE
===============================================================================*/

class graphNode{
// not templated because I assume Euclidean distance is always an integer. 
private:


public:
	int h;													// h(n) the heuristic 
	int g;													// g(n) the distance from start to node n
	int f;													// f(n)	resulting cost
	graphNode *leftPtr;										// left node
	graphNode *rightPtr;									// right node

	graphNode(int x, int y, int z){

	}


};


// function declarations
void poolSimulation(SL_PriorityQueue<int>& );
void AStar(graphNode *start, graphNode *finish, SL_PriorityQueue<int> *AStarQueue);



int main(int argc, char *argv[], char *envp[]){



///////////////// Exercise 2 section ////////////////////////////

	SL_PriorityQueue<char> charQueue;
	std::string name = "Abigail";

	std::cout << "\n\n";
	for(unsigned int i = 0; i  < name.length(); ++i){
		charQueue.enqueue(name[i]);
	}
	std::cout << "\n";
	charQueue.showQueue();
	std::cout << "\n";
	
	// this is a testing section to show that showQueue() works
	/*
	std::cout << "first dequeue is " << charQueue.dequeue() << std::endl;
	std::cout << "\n";
	charQueue.showQueue();
	std::cout << "\n";
	std::cout << "second dequeue is " << charQueue.dequeue() << std::endl;
	std::cout << "\n";
	charQueue.showQueue();
	std::cout << "\n";
	std::cout << "third dequeue is " << charQueue.dequeue() << std::endl;
	std::cout << "\n";
	charQueue.showQueue();
	std::cout << "\n";
	*/

////////////////////// Pool Simulation ///////////////////////////

	//SL_PriorityQueue<int> intQueue;


	// thought we had to make the pool simulation, half started
	//poolSimulation(intQueue);									


///////////////////// A* implementation /////////////////////////////////


	//graphNode *startGraph = new graphNode();

	//AStar()

	//delete startGraph;

///////////////////////////////////////////////////////////////////

/////////////////// RedBlob games Code /////////////////////////////


  GridWithWeights grid = make_diagram4();

  GridLocation start{1, 4};
  GridLocation goal{8, 5};

  std::map<GridLocation, GridLocation> came_from;

  std::map<GridLocation, double> cost_so_far;

  a_star_search(grid, start, goal, came_from, cost_so_far);
  draw_grid(grid, 2, nullptr, &came_from);

  std::cout << '\n';

  draw_grid(grid, 3, &cost_so_far, nullptr);

  std::cout << '\n';
  std::vector<GridLocation> path = reconstruct_path(start, goal, came_from);

  draw_grid(grid, 3, nullptr, nullptr, &path);


//////////////////////////////////////////////////////////////////

	return 0;
}

/*=============================================================================
FUNCTION:          poolSimulation(SL_PriorityQueue<int>& queue)
DESCRIPTION:       meant to simulate a pool table
NOTE:			   Left in here because I thought we had to actually make a pool
					simulation and figured I would leave it
STATUS:			   INCOMPLETE
===============================================================================*/

void poolSimulation(SL_PriorityQueue<int>& queue){

	int poolTable[7][7] = { 
						  { 0 , 0 , 0 , 0 , 0 , 0 , 0},
						  { 0 , 0 , 0 , 0 , 0 , 0 , 0},
						  { 0 , 0 , 0 , 5 , 0 , 0 , 0},
						  { 0 , 0 , 4 , 2 , 4 , 0 , 0},
						  { 0 , 3 , 2 , 1 , 2 , 3 , 0},
						  { 0 , 0 , 0 , 0 , 0 , 0 , 0},
						  { 0 , 0 , 0 , 0 , 0 , 0 , 0},
						  };

	for(int n = 0; n < 7; ++n){					// a matric with n rows and m columns
		for(int m = 0; m < 7; ++m){
			if(poolTable[n][m]){ 
				queue.enqueue(poolTable[n][m]);
			}
		}
	}
		queue.showQueue();


}


/*=============================================================================
FUNCTION:          poolSimulation(SL_PriorityQueue<int>& queue)
DESCRIPTION:       meant to simulate a pool table
NOTE:			   Attempted to make my own A* algorithm, ran out of time
STATUS:			   INCOMPLETE
===============================================================================*/


void AStar(graphNode *start, graphNode *finish, SL_PriorityQueue<int> &AStarQueue){
// let's assume we are moving from start to finish

}