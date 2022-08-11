#include <iostream>
#include <vector>

using namespace std;

int dfs(const vector<vector<int>> &adj, vector<bool> &vis, int u) {
	if (vis[u])
		return u;
	vis[u] = true;
	for (int v: adj[u]) {
		if (!vis[v])
			dfs(adj, vis, v);
	}
	return u;
}

int main() {
	int n,m,u,v;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int resCount = 0;
	vector<bool> vis(n + 1, false);
	vector<pair<int, int> > res;
	int lastComponentVertex = 0; // keeps any vertex from last scanned component
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int foundVertex = dfs(adj, vis, i);
			if (lastComponentVertex != 0)
				res.push_back({lastComponentVertex, foundVertex});
			lastComponentVertex = foundVertex;
		}
	}
	cout << res.size() << endl;
	for (auto p: res)
		cout << p.first << " " << p.second << endl; 
	return 0;
}