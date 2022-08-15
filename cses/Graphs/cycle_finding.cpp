#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

#define LL long long int

int main () {
	int n,m,u,v,w;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edges.push_back(make_tuple(u,v,w));
	}
	vector<LL> dist(n + 1, INT_MAX);
	vector<int> parent(n + 1, -1);
	int lastNegNode;
	for (int i = 1; i <= n; i++) {
		lastNegNode = -1;
		for (auto edge: edges) {
			tie(u,v,w) = edge;
			LL cost = dist[u] + w;
			if (cost < dist[v]) {
				dist[v] = cost;
				parent[v] = u;
				if (i == n)
					lastNegNode = v;
			}
		}
	}
	if (lastNegNode != -1) {
		cout << "YES" << endl;
		int x = lastNegNode;
		for (int i = 1; i <= n; i++)
			x = parent[x];
		int y = x;
		vector<int> cycle;
		do {
			cycle.push_back(y);
			y = parent[y];
		} while (y != x);
		cycle.push_back(cycle[0]);
		reverse(cycle.begin(), cycle.end());
		for (int v : cycle)
			cout << v << " ";
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}