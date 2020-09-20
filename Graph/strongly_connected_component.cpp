#include <iostream>
#include <vector>
#include <stack>
#include <functional>

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

	Graph transpose() const {
		Graph other(this->V, this->isDirected);
		for (int u = 0; u < this->V; u++) {
			for (int v: this->adj[u]) {
				other.adj[v].push_back(u);
			}
		}
		return other;
	}
};

vector<vector<int>> findSsc(const Graph&);
void dfs(const Graph &g, 
		 vector<bool> &vis, 
		 int, 
		 function<void(int)> postConsumer = [](int){});


int main () {
	Graph g(5);
	g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 

    vector<vector<int>> res = findSsc(g);
    for (vector<int> &comp: res) {
    	for (int v : comp) {
    		cout << v << " ";
    	}
    	cout << endl;
    }
	return 0;
}

vector<vector<int>> findSsc(const Graph &g) {
	int V = g.V; 
	vector<bool> vis(V, false);
	stack<int> stk;
	
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs(g, vis, i, [&](int v){
				stk.push(v); // this consumer function will add each processed node to stack
			});
		}
	}
	fill(vis.begin(), vis.end(), false); // mark vis to all false
	Graph transposedGraph = g.transpose();

	vector<vector<int>> res;
	while (!stk.empty()) {
		int v = stk.top();
		stk.pop();
		vector<int> component;
		if (!vis[v]) {
			dfs(transposedGraph, vis, v, [&](int v){
				component.push_back(v);
			});
		}
		res.push_back(component);
	}
	return res;
}

void dfs(const Graph &g, vector<bool> &vis, int u, function<void(int)> consumer) {
	vis[u] = true;
	for (int v : g.adj[u]) {
		if (!vis[v]) {
			dfs(g, vis, v, consumer);
		}
	}
	consumer(u);
}