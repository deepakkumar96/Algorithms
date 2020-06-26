
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

class UnionFind {
public:
    UnionFind(int n): size(n){
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }
    int unite(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        parent[parentB] = parent[parentA];
    }
    bool isSame(int a, int b) {
        return find(a) == find(b);
    }
private:
    int *parent;
    int size;
};

enum Color {
    WHITE,
    BLACK,
    GRAY
};

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtilDirected(int u, vector<bool> &vis, vector<Color> &colors);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic(bool isDirected);    // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}



int main() {

    Graph directedGraph(4);

    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 2);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 0);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 3);


    if (directedGraph.isCyclic(true)) {
        cout << "Directed graph has cycle." << endl;
    } else {
        cout << "Directed graph does not has cycle." << endl;
    }

    cout << endl;

    Graph unDirectedGraph(4);
    unDirectedGraph.addEdge(0, 1);
    unDirectedGraph.addEdge(1, 0);

    unDirectedGraph.addEdge(0, 2);
    unDirectedGraph.addEdge(2, 0);

    unDirectedGraph.addEdge(1, 2); // removing or commenting this edge will remove loop from undirected graph
    //unDirectedGraph.addEdge(2, 1);

    unDirectedGraph.addEdge(2, 3);
    unDirectedGraph.addEdge(3, 2);

    if (unDirectedGraph.isCyclic(false)) {
        cout << "Un-Directed graph has cycle." << endl;
    } else {
        cout << "Un-Directed graph does not has cycle." << endl;
    }

    return 0;
}


bool Graph::isCyclic(bool isDirectedGraph) {
    if (isDirectedGraph) {
        int n = this->V;
        vector<bool> vis(n, false);
        vector<Color> colors(n, WHITE);

        for (int i = 0; i < n; i++) {
            if (!vis[i] && colors[i] == WHITE) {
                bool hasCycle = isCyclicUtilDirected(i, vis, colors);
                if (hasCycle) {
                    return true;
                }
            }
        }
        return false;
    } else {
        // If undirected graph
        // using union-find
        UnionFind uf(V);

        // creating edge set from adj-list
        set<pair<int, int>> edges;

        for (int u = 0; u < V; u++) {
            for (int v: adj[u]) {
                int a = min(u, v);
                int b = max(u, v);
                pair<int, int> edge = {a, b};
                if (edges.find(edge) == edges.end()) {
                    edges.insert(edge);
                }
            }
        }

        // finding cycle in undirected graph
        for (auto edge: edges) {
            int a = edge.first;
            int b = edge.second;
            if (!uf.isSame(a, b)) {
                uf.unite(a, b);
            } else {
                return true;
            }
        }
        return false;
    }
}

bool Graph::isCyclicUtilDirected(int u, vector<bool> &vis, vector<Color> &colors) {
    vis[u] = true;
    colors[u] = GRAY;
    for (int v: this->adj[u]) {
        if (!vis[v] && isCyclicUtilDirected(v, vis, colors)) {
            return true;
        } else if (colors[v] == GRAY) { // if still in recursion stack
            return true;
        }
    }
    colors[u] = BLACK;
    return false;
