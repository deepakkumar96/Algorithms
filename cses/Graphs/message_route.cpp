#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> findPath(const vector<vector<int>> &adj, int source, int dest) {
	int n = adj.size();
	vector<bool> vis(n, false);
	vector<int> parent(n + 1, 0);
	queue<int> que;
	que.push(source);
	vis[source] = true;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int v : adj[u]) {
			if (!vis[v]) {
				vis[v] = true;
				parent[v] = u;
				que.push(v);
			}
		}
	}
	vector<int> path;
	if (vis[dest]) { //path exist
		int p = dest;
		while (p != source) {
			path.push_back(p);
			p = parent[p];
		}
		path.push_back(p);
		reverse(path.begin(), path.end());
	}
	return path;
}

int main () {
	int n,m,u,v;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> path = findPath(adj, 1, n);
	if (path.size() == 0)
		cout << "IMPOSSIBLE" << endl;
	else {
		cout << path.size() << endl;
		for (int v : path) 
			cout << v << " "; 
	}
	return 0;
} 