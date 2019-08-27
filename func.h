#include <cstdlib>
using namespace std;

class LinkedList {
private:
	struct node {
		int index;
		char dir;
		bool visited;
		node *next;
	};

	node *header;
	node *cursor;

public:
	LinkedList();
	void insertNode(int newIndex, char newDir);
	int getNeighbor(int vertex);
	char getDirection(int vertex);
	bool isVisited();
	void setToVisited();

	void printList();
};

LinkedList::LinkedList() {
    header = NULL;
    cursor = NULL;
}

void LinkedList::insertNode(int newIndex, char newDir) {
	node * newNode = new node;
	newNode->index = newIndex;
	newNode->dir = newDir;
	newNode->visited = false;
	newNode->next = NULL;

	if (header == NULL) 
		header = newNode;
	else {
		cursor = header;
		while (cursor->next != NULL)	/* iterates until at last node */
			cursor = cursor->next;
		cursor->next = newNode; 		/* adds node to end of list */
	}
}

int LinkedList::getNeighbor(int vertex) {
	cursor = header;
	for (int i = 0; i < vertex; i++) {
		if (cursor->next == NULL)
			return -1;					/* no neighbors left */
		cursor = cursor->next;
	}
	return cursor->index;
}

char LinkedList::getDirection(int vertex) {
	cursor = header;
	for (int i = 0; i < vertex; i++) {
		cursor = cursor->next;
	}
	return cursor->dir;
}

bool LinkedList::isVisited() {
	cursor = header;
	return cursor->visited;
}

void LinkedList::setToVisited() {
	cursor = header;
	cursor->visited = true;
}