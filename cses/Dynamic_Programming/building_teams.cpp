#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool dfs(const vector<vector<int>> &adj, vector<bool> &vis, vector<int> &teams, int u, int parent, lastTeamNo) {
	visited[u] = true;
	int newTeamNo = (lastTeamNo == 1) ? 2: 1;
	teams[u] = nextTeamNo;
	for (int v : adj[u]) {
		if (!vis[v]) {
			vis[v] = true;
			if (dfs(adj, vis, teams, v, u, newTeamNo))
				return true; // detected cycle
		} else if (v != parent) {
			// if already visited is not equal to parent, then cycle is detected
			return true;
		}
	}
	return false;
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
	vector<int> teams(n + 1, 1);
	vector<bool> vis(n + 1, false);
	bool hasCycle = dfs(adj, vis, teams, 1, 1, 1);
	if (hasCycle)
		cout << "IMPOSSIBLE" << endl;
	else 
		for (int v: colors) 
			cout << v << " ";
	return 0;
}