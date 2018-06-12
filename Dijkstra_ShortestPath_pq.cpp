#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

#define INF 0x3F3F3F3F
// pair of vertex and weight
typedef pair<int, int> vpair;

class Graph {
    private:
        int vertices;
        list<vpair>* ptr;
    public:
        Graph(int vertices);
        void addEdge(int u, int v, int weight);
        void path(int source);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    ptr = new list<vpair>[vertices];
}

void Graph::addEdge(int u, int v, int weight) {
    ptr[u].push_back(make_pair(v, weight));
    ptr[v].push_back(make_pair(u, weight));
}

void Graph::path(int source) {
    priority_queue< vpair, vector<vpair>, greater<vpair> > pq;
    vector<int> dist(vertices, INF); // this is the result vector
    pq.push(make_pair(0, source));
    dist[source] = 0;
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<vpair>::iterator i;
        for(i = ptr[u].begin(); i != ptr[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            // dist[v] = weight;
            // Notice that initial value of dist[v] is INFINITE
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex distance from source " << endl;
    for(int i = 0; i < vertices; ++i) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int vertices = 9;
    Graph g(vertices);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
    g.path(0);
    
    return 0;
}
