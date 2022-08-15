#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

void dfs(const vector<vector<int>> &adj, vector<bool> &vis, int u) {
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v]) dfs(adj, vis, v);
}

int main() {
	int n,m,u,v,w;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges(m + 1);
	vector<vector<int>> adj(n + 1);
	vector<vector<int>> reverseAdj(n + 1);
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edges[i] = make_tuple(u, v, w * -1);
		adj[u].push_back(v);
		reverseAdj[v].push_back(u);
	}
	vector<bool> vis(n + 1), reverseVis(n + 1);
	dfs(adj, vis, 1);
	dfs(reverseAdj, reverseVis, n);

	//bellman-ford shortest path
	vector<long long int> dist(n + 1, 1e18);
	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (auto edge: edges) {
			tie(u, v, w) = edge;
			if ((dist[u] + w) < dist[v]) {
				dist[v] = dist[u] + w;
				// detecting negative cycle
				if (i == n && vis[v] && reverseVis[v]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	// looping over for nth roung to find negative cycle
	/*for (auto edge : edges) {
		tie(u, v, w) = edge;
		if (dist[u] + w < dist[v]) { // negative cycle
			cout << -1 << endl;
			return 0;
		}
	}*/
	cout << (dist[n] * -1) << endl;
	return 0;
}