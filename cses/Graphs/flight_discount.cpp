#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

#define LL long long int

vector<LL> dijkstra(const vector<vector<pair<int, int>>> &adj, int source, int n, int m) {
	vector<LL> dist(n + 1, LLONG_MAX);
	vector<bool> vis(n + 1, false);
	priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
	//init
	dist[source] = 0;
	pq.push({0, source});
	while (!pq.empty()) {
		auto u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto p: adj[u]) {
			int v = p.first;
			int w = p.second;
			LL newCost = dist[u] + w;
			if (newCost < dist[v]) {
				dist[v] = newCost;
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}

void dump(vector<long long> dist) {
	for (int v : dist) {
		cout << v << " ";
	}
	cout << endl;
}

int main () {
	int n, m, u, v, w;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<vector<pair<int, int>>> reverseAdj(n + 1);
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		reverseAdj[v].push_back({u, w});
		edges.push_back({u, v, w});
	}
	vector<LL> sourceDist = dijkstra(adj, 1, n, m);
	vector<LL> destDist = dijkstra(reverseAdj, n, n, m);
	//dump(sourceDist); dump(destDist);
	LL maxRes = LLONG_MAX;
	for (auto edge : edges) {
		tie(u,v,w) = edge;
		if (sourceDist[u] == LLONG_MAX || destDist[v] == LLONG_MAX) continue;
		LL cost = sourceDist[u] + (w/2) + destDist[v];
		maxRes = min(cost, maxRes);
	}
	cout << maxRes << endl;
	return 0;
}