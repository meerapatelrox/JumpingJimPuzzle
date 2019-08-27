#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include "func.h"
using namespace std;

int row, col;
queue<int> values;
vector < pair<int, char> > path;

void readFile() {
	cout << "Enter the name of the input file, including extension: ";
	string input_file;
	cin >> input_file;
	
	ifstream pFile;
	pFile.open(input_file);

	if (!pFile.is_open())
		exit(1);
	else
		cout << "Reading file." << endl;
	
	int temp; 

	pFile >> row;
	pFile >> col;

	while (!pFile.eof()) {
		pFile >> temp;
		values.push(temp);
	}

	pFile.close();
}

void solveMaze() {
	cout << "Solving maze." << endl;
	
	/* PART ONE: TAKE THE INPUT AND PUT IT IN A 2D ARRAY */
	int map[row][col];
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			map[i][j] = values.front();
			values.pop();
		}
	}

	/* PART TWO: MAKE THE ADJACENCY LIST FROM THE 2D ARRAY */
	LinkedList *adjList = new LinkedList[row * col]; 		/* dynamic array of type LinkedList */

	for (i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {						/* for one element of the adjList */
			LinkedList myNeighbors; 						/* declare single LinkedList for that one vertex's neighbors */

			/* if cannot jump */
			if (map[i][j] == 0) {
				myNeighbors.insertNode(-1, 'X');
				adjList[(i * row) + j] = myNeighbors;
				continue;
			}

			/* if all neighbors are outside the map */
			if ((i - map[i][j] < 0) && (i + map[i][j] >= row) && (j + map[i][j] >= col) && (j - map[i][j] < 0)) {
				myNeighbors.insertNode(-1, 'X');
				adjList[(i * row) + j] = myNeighbors;
				continue;
			}

			/* caculate neighbor to the north */
			if (i - map[i][j] >= 0) 
				myNeighbors.insertNode((i - map[i][j]) * row + j, 'N');

			/* caculate neighbor to the west */
			if (j - map[i][j] >= 0) 
				myNeighbors.insertNode((j - map[i][j]) + i * row, 'W');

			/* caculate neighbor to the east */
			if (j + map[i][j] < col) 
				myNeighbors.insertNode((j + map[i][j]) + i * row, 'E');

			/* caculate neighbor to the south */
			if (i + map[i][j] < row) 
				myNeighbors.insertNode((i + map[i][j]) * row + j, 'S');

			adjList[(i * row) + j] = myNeighbors;
		}
	}

    /* PART THREE: TRAVERSE THROUGH DFS */
    int vtx = 0, nbr = 0;
    adjList[0].setToVisited();
    int exit = row * col - 1;

    while (vtx != exit) {									/* while we are not currently at the exit */
    	pair <int, char> jump;

    	/* if current vertex has a neighbor that has been visited */
    	if (adjList[vtx].getNeighbor(nbr) >= 0 && adjList[adjList[vtx].getNeighbor(nbr)].isVisited()) {
    		nbr++;											/* move on to next neighbor */
    		continue;
    	}

    	/* if current vertex has a neighbor that is unvisited */
    	if (adjList[vtx].getNeighbor(nbr) >= 0) {
    		jump.first = vtx;								/* store vertex we are at */
    		jump.second = adjList[vtx].getDirection(nbr);	/* store direction we are going from this vertex */
    		vtx = adjList[vtx].getNeighbor(nbr);			/* jump to neighbor, making it the current vertex */
    		nbr = 0;										/* set explored neighbors back to 0 */
    		adjList[vtx].setToVisited();					/* mark current vertex as visited */
    		path.push_back(jump);							/* add the jump we just made to the path */
    	} else { 											/* if getNeighbor < 0, i.e. no more neighbors to explore */
    		vtx = path[path.size() - 1].first;	
    		nbr = 0;
    		path.resize(path.size() - 1);
    	}
    }
}

void writeFile() {
	cout << "Enter the name of the output file, including extension: ";
	string output_file;
	cin >> output_file;
	
    ofstream qFile;
    qFile.open(output_file);

    for (int i = 0; i < path.size(); i++) {
    	qFile << path[i].second << " ";
    }
    qFile.close();
	
	cout << "Solution written to output file!" << endl;
}

int main(void) {
	readFile();
	solveMaze();
	writeFile();
}