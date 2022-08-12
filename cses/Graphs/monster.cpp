#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int[] xs = {-1,  0,  1,  0};
int[] ys = { 0, -1,  0,  1};

char getDirection(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) // diff in x pos
		return b.first > a.first ? 'R' : 'L';
	return b.second > a.second ? 'D' : 'U';
}

vector<vector<int>> findMonsterDist(const vector<string> &map, const vector<pair<int, int>> &monPos, int n, int m) {
	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
	vector<vector<int>> dist(n + 1, vector<int>(m + 1, INT_MAX));
	queue<pair<int, int>> q;
	for (auto p: monPos) {
		q.push(p);
		vis[p.first][p.second] = true;
		dist[p.first][p.second] = 0;
	}
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int px = u.first + xs[i];
			int py = u.second + ys[i];
			if (!vis[px][py] && map[px][py] != '#') {
				vis[px][py] = true;
				dis[px][py] = dis[u.first][u.second] + 1;
				q.push({px, py});
			}
		}
	}
	return dist;
}

string findPLayerPath(const vector<string> &map, pair<int, int> pPos, const vector<vector<int>> &mDist, int n, int m) {
	int px = pPos.first;
	int py = pPos.seocnd;
	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
	vector<vector<int>> pDist(n + 1, vector<int>(m + 1, INT_MAX));
	vector<vector<pair<int, int>>> parent(n + 1, vector<pair<int, int>>(m + 1, {}));
	queue<pair<int, int>> que;
	//init
	que.push(pos);
	dis[px][py] = 0;
	vis[px][py] = true;
	parent[px][py] = pos;
	pair<int, int> boundryPos = {-1, -1};
	while (!que.empty()) {
		auto u = que.front();
		int ux = u.first;
		int uy = u.second;
		que.pop();
		if (isBoundry(u)) {
			boundryPos = u;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int vx = ux + xs[i];
			int vy = uy + yx[i];
			int dist = pDist[ux][uy] + 1;
			if (!vis[vx][vy] && map[vx][vy] != '#' && dis < mDist[vx][vy]) {
				vis[vx][vy] = true;
				parent[vx][vy] = u;
				pDist[vx][vy] = dist;
				que.push({vx, vy});
			}
		}
	}
	string path;
	if (boundryPos.first != -1) {
		pair<int, int> p = boundryPos;
		while (p != pPos) {
			path += getDirection(parent[p.first][p.second], p);
			p = parent[p.first][p.second];
		}
		path += getDirection(p);
		reverse(path.begin(), path.end());
	}
	return path; // no path exist if it's empty
}

int main () {
	int n,m,u,v;
	cin >> n >> m;
	vector<string> map(n + 1);
	pair<int, int> player;
	vector<pair<int, int>> monsters;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < map[i].size(); j++) {
			char c = map[i][j];
			if (c == 'A')
				player = {i, j};
			else if (c == 'M')
				monsters.push_back({i, j});
		}
	}
	vector<vector<int>> mdis(n + 1, m + 1) = findMonsterDist(map, monsters);
	string path = findPlayerPath(map, player, mdis);
	if (!path.empty())
		cout << "YES" << endl << path.size() << endl << path << endl;
	else
		cout << "IMPOSSIBLE" << endl;
	int return 0;
}