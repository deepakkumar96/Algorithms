#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Graph {
public:
	Graph(int n);
	void addEdge(int, int, int);
	void addDirectedEdge(int, int, int);
	vector<pair<int, int>> edges(int);
	vector<int> findShortestPath(int, int);
	int findShortestDistance(int, int);
	int size();
private:
	pair<vector<int>, vector<int>> dijkstra(Graph*, int);
	vector<int> bellmanFord(Graph*, int);
	vector<pair<int, int>> *adj;
	size_t _size;
};

int main() {
	int n = 5;
	Graph g(n);
	g.addDirectedEdge(0, 1, 4);
	g.addDirectedEdge(0, 2, 1);
	g.addDirectedEdge(1, 3, 1);
	g.addDirectedEdge(2, 1, 20);
	g.addDirectedEdge(2, 3, 5);
	g.addDirectedEdge(3, 4, 3);

	int a = 0, b = 4;

	auto sd = g.findShortestDistance(a, b);
	cout << "shortest dist from " << a << " to " << b << " is " << sd << endl;
	
	cout << "path : ";
	for (auto v: g.findShortestPath(a, b)) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

Graph::Graph(int n) {
	_size = n;
	adj = new vector<pair<int, int>>[n];
}

int Graph::size() {
	return _size;
}

void Graph::addEdge(int source, int dest, int cost) {
	adj[source].push_back({cost, dest});
	adj[dest].push_back({cost, source});
}

void Graph::addDirectedEdge(int source, int dest, int cost) {
	adj[source].push_back({cost, dest});
}

vector<pair<int, int>> Graph::edges(int u) {
	return adj[u];
}

int Graph::findShortestDistance(int source, int dest){
	auto distAndPath = dijkstra(this, source); //bellmanFord(this, source);
	/*for (auto v: distAndPath) {
		cout << v << " ";
	}*/
	return distAndPath.first[dest];
}

vector<int> Graph::findShortestPath(int source, int dest) {
	auto distAndPath = dijkstra(this, source);
	vector<int> distance = distAndPath.first;
	vector<int> path = distAndPath.second;
	vector<int> shortestPath;
	if (distance[dest] == INT_MAX) {
		return shortestPath; //no path found return empty path
	}
	shortestPath.push_back(dest); // add destination	
	for (int i = dest; i != -1; i = path[i]) {
		if (path[i] != -1) {
			shortestPath.push_back(path[i]);
		}
	}
	reverse(shortestPath.begin(), shortestPath.end());
	return shortestPath;
}

pair<vector<int>, vector<int> > Graph::dijkstra(Graph *g, int source) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

	vector<int> dist(g->size(), INT_MAX);
	vector<int> path(g->size(), -1);
	vector<bool> vis(g->size(), false);

	pq.push({0, source});
	dist[source] = 0;

	while(!pq.empty()) {
		auto u = pq.top().second;
		pq.pop();
		vis[u] = true;
		for (auto v: g->edges(u)) {
			auto nodeV = v.second; //first as weight and second as node value
			auto vCost = v.first;
			if (!vis[nodeV]) {
				auto newDist = dist[u] + vCost;
				if(newDist < dist[nodeV]) {
					dist[nodeV] = newDist;
					path[nodeV] = u;
				}
				//vis[nodeV] = true;
				pq.push({newDist, nodeV});
			}
		}
	}
	return {dist, path};
}

vector<int> Graph::bellmanFord(Graph *g, int source) {
	size_t sz = g->size();
	vector<int> dist(sz, INT_MAX);
	dist[source] = 0;
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz; j++) {
			for (auto v: g->edges(j)) {
				dist[v.second] = min(dist[v.second], dist[j] + v.first);
			}
		}
	}
	return dist;
}