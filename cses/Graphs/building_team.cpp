#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool dfs(const vector<vector<int>> &adj, vector<int> &teams, int u, int parent, int lastTeamNo) {
	teams[u] = (lastTeamNo == 1) ? 2: 1;
	for (int v : adj[u]) {
		if (teams[v] == 0) {
			if (!dfs(adj, teams, v, u, teams[u]))
				return false; // detected cycle
		} else if (teams[u] == teams[v]) {
			return false;
		}
	}
	return true;
}

/*
	team of:
		0 => not assigned
		1 => 1st team
		2 => 2nd team
*/
vector<int> buildTeamDfs(const vector<vector<int>> &adj, int n, int m) {
	vector<int> teams(n + 1, 0);
	bool isValidRes = true;
	for (int i = 1; i <= n; i++) {
		if (teams[i] == 0 && !dfs(adj, teams, i, i, 2)) {
			isValidRes = false;
		}
	}
	if (isValidRes)
		return teams;
	return {};
}

bool bfs(const vector<vector<int>> &adj, vector<int> &teams, int node, int n, int m) {
	queue<int> que;
	//init
	que.push(node);
	teams[node] = 1;
	auto nextTeam = [&](int t) { return t == 1 ? 2 : 1;}; // lambda to get next team
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int v : adj[u]) {
			if (teams[v] == 0) {
				teams[v] = nextTeam(teams[u]);
				que.push(v);
			} else if (teams[u] == teams[v])
				return false; // return empty result indicating IMPOSSIBLE to select team.
		}
	}
	return true;
}

vector<int> buildTeamBfs(const vector<vector<int>> &adj, int n, int m) {
	vector<int> teams(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (teams[i] == 0)
			if (!bfs(adj, teams, i, n, m))
				return {};
	}
	return teams;
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
	vector<int> teams = buildTeamBfs(adj, n, m);
	if (teams.empty())
		cout << "IMPOSSIBLE" << endl;
	else 
		for (int i = 1; i <= n; i++) 
			cout << teams[i] << " ";
	cout << endl;
	return 0;
}