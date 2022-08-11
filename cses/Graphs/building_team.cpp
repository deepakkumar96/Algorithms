#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool dfs(const vector<vector<int>> &adj, vector<int> &teams, int u, int parent, int lastTeamNo) {
	teams[u] = (lastTeamNo == 1) ? 2: 1;
	for (int v : adj[u]) {
		if (teams[v] == 0) {
			//teams[v] = 
			if (!dfs(adj, teams, v, u, teams[u]))
				return false; // detected cycle
		} else if (teams[u] == teams[v]) {
			// if already visited is not equal to parent, then cycle is detected
			return false;
		}
	}
	return true;
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
	vector<int> teams(n + 1, 0);
	bool isValidRes = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && !dfs(adj, teams, i, i, 2)) {
			isValidRes = false;	
		}
	}
	if (!isValidRes)
		cout << "IMPOSSIBLE" << endl;
	else 
		for (int i = 1; i <= n; i++) 
			cout << teams[i] << " ";
	return 0;
}