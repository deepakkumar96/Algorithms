#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define LL long long

int main () {
	const LL MAX = 10e16;
	int n,m,q,a,b;
	LL c;
	cin >> n >> m >> q;
	vector<vector<LL>> dist(n + 1, vector<LL>(n + 1, MAX));
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][a] = 0;
		dist[b][b] = 0;
		dist[a][b] = min(c, dist[a][b]);
		dist[b][a] = min(c, dist[b][a]);
	}
	//floyd-warshall algorithm
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		LL cost = (dist[a][b] == MAX) ? -1 : dist[a][b];
		cout << cost << endl;
	}
	return 0;
}