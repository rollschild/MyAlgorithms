// represent a graph using adjacent list.
#include <iostream>
#include <vector>
using namespace std;
// we do NOT actually add new nodes
// because all nodes are hardcoded in the vector
// it's same as vector.size()
struct Node {
	int val;
	struct Node* next;
};

// why do we need this???
struct NodeList {
	struct Node* tail;
    // this tail is not actually the element or index in the vector
    // it's the first vertex of the NodeList
    // it can be treated as outside of the vector
};

struct Graph {
	int vertex;
	vector<struct NodeList*> vec;
};

struct Node* createNode(int val) {
	struct Node * node = new Node();
	node->val = val;
	node->next = nullptr;
	return node;
};

// to create a graph with V vertices
// vector of NodeLists -> NodeLists -> nodes
struct Graph* addGraph(int vertices) {
	struct Graph* graph = new Graph();
	graph->vertex = vertices;
	graph->vec.resize(vertices);
	// graph->vec = malloc(vertices * (sizeof(struct NodeList)));
	for(int i = 0; i < graph->vertex; ++i) {
		graph->vec[i] = new NodeList();
		graph->vec[i]->tail = nullptr;
	}
	return graph;
};

void addEdge(struct Graph* graph, int vertex, int dest) {
	// all nodes already exist
    // we need to connect them
    // we will create different paths
    struct Node* node = createNode(dest);
	// graph->vec[vertex]->tail = node;
    // a node is added to the beginning
	node->next = graph->vec[vertex]->tail;
	graph->vec[vertex]->tail = node;

	node = createNode(vertex);
	// graph->vec[dest]->tail = node;
	node->next = graph->vec[dest]->tail;
	graph->vec[dest]->tail = node;
}

void printGraph(struct Graph* graph) {
	int vertices = graph->vertex;
	cout << "The graph is: " << endl;
	for(int i = 0; i < vertices; ++i) {
		cout << "Vertex " << i << " ";
		struct Node* node = graph->vec[i]->tail;
		while(node) {
			cout << "->" << " " << node->val << " ";
			node = node->next;
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	struct Graph* g = addGraph(8);
	
	addEdge(g, 3, 5);
	addEdge(g, 0, 2);
	addEdge(g, 0, 1);
	addEdge(g, 0, 4);
	addEdge(g, 2, 1);
	addEdge(g, 5, 1);
	addEdge(g, 5, 4);
	addEdge(g, 3, 4);
    addEdge(g, 7, 1);
    addEdge(g, 7, 3);
    addEdge(g, 7, 2);
    addEdge(g, 7, 4);
    addEdge(g, 7, 6);
	printGraph(g);
	return 0;
}
