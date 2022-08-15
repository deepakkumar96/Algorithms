#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

enum State {
	NOT_FOUND, FOUND, PROCESSED
};

struct CycleState {
	int cycleVertex;
	State state;
	CycleState(int v, State s): cycleVertex(v), state(s) { }
	CycleState(int v): cycleVertex(v), state(FOUND) {}
	bool isCycleFound() { return state == FOUND; }
	bool isProcessed() {return state == PROCESSED; }
	void setState(State state) { this->state = state;}
	static CycleState notFound() { return CycleState(0, NOT_FOUND);}
};

CycleState dfs(const vector<vector<int>> &adj, vector<bool> &vis, vector<int> &result, int u, int parent) {
	vis[u] = true;
	for (int v: adj[u]) {
		if (!vis[v]) {
			auto cycleState = dfs(adj, vis, result, v, u);
			if (cycleState.isProcessed()) //denotes that cycle has already been found & processed
				return cycleState;
			if (cycleState.isCycleFound()) {
				//backtracking, when cycle has been found
				result.push_back(v);
				if (cycleState.cycleVertex == u) {
					//reached to start of the cycle
					result.push_back(u);
					cycleState.setState(PROCESSED); //marking that entire cycle is added into result, and to stop dfs
				}
				return cycleState;
			}
		} else if (v != parent) {
			// cycle found
			//cout << "cycle\n";
			result.push_back(v);
			return CycleState(v);
		}
	}
	return CycleState::notFound();
}

int main () {
	int n,m,u,v;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	vector<bool> vis(n + 1, false);
	vector<int> index(n + 1, 0);
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && result.empty()) dfs(adj, vis, result, i, i);
	}
	if (result.empty())
		cout << "IMPOSSIBLE";
	else {
		//reverse(result.begin(), result.end());
		cout << result.size() << endl;
		for (int v : result)
			cout << v << " ";
	}
	cout << endl;
	return 0;
}



/*

5 7
1 2
2 1
1 3
1 5
5 3
2 4
4 5

*/