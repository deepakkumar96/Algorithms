#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

using namespace std;

class Graph {
public:
	vector<vector<int>> adj;
	bool isDirected;
    int V;
	Graph(int v, bool type = true): V(v), isDirected(type) {
		adj.resize(v);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		if (!isDirected) {
			adj[v].push_back(u);
		}
	}
};

enum Color {WHITE, GRAY, BLACK};

vector<int> topologicalSort(Graph&);
bool dfs(const Graph &, vector<Color> &, stack<int> &, int);

int main() {
	
	Graph g(6);

	g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);
    g.addEdge(0, 5);

    vector<int> res = topologicalSort(g);
    if (res.empty()) {
    	cout << "Graph has cycle, topological sort not possible" << endl;
    } else {
	    for (int v : res) {
	    	cout << v << " ";
	    }
	    cout << endl;
    }
	return 0;
}

vector<int> topologicalSort(Graph &g) {
	assert(g.isDirected);
	int V = g.V;
    vector<Color> state(V, WHITE);
	stack<int> stk;

	for (int i = 0; i < V; i++) {
		if (state[i] == WHITE) {
			if (!dfs(g, state, stk, i)) {
				return {}; // topological sort not possible
			}
		}
	}
	vector<int> res(V, 0);
	for (int i = 0; i < V; i++) {
		res[i] = stk.top();
		stk.pop();
	}
	return res;
}

/* 
	Returns true if there is no-cycle else return false
*/
bool dfs(const Graph &g, vector<Color> &state, stack<int> &stk, int u) {
    state[u] = GRAY;
    for (int v : g.adj[u]) {
        if (state[v] == WHITE && !dfs(g, state, stk, v)) {
            return false;
        } else if (state[v] == GRAY) {
            return false; // cycle found, topological-sort not possible, so return false;
        }
    }
    state[u] = BLACK;
    stk.push(u);
    return true;
}
