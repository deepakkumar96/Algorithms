#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

#define LL long long


vector<LL> shortestPath(const vector<vector<pair<int, int>>> &adj, int n, int m) {
	vector<LL> dist(n + 1, LLONG_MAX);
	vector<bool> vis(n + 1, false);
	priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto p: adj[u]) {
			int v = p.first;
			int w = p.second;
			LL cost = dist[u] + w;
			if (cost < dist[v]) {
				dist[v] = cost;
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}

int main() {
	int n,m,u,v,w;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	vector<LL> path = shortestPath(adj, n, m);
	for (int i = 1; i <= n; i++) {
		cout << path[i] << " ";
	}
	cout << endl;
	return 0;
}