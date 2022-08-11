	#include<iostream>
	#include<vector>

	using namespace std;

	vector<pair<int, int>> childs(const vector<string> &map, int r, int c, int m) {
		int n = map.size();
		vector<pair<int, int>> pairs;
		if (r - 1 >= 0)
			pairs.push_back({r - 1, c});
		if (r + 1 < n)
			pairs.push_back({r + 1, c});
		if (c - 1 >= 0)
			pairs.push_back({r, c - 1});
		if (c + 1 < m)
			pairs.push_back({r, c + 1});
		return pairs;
	}

	bool dfs(const vector<string> &map, vector<vector<bool>> &vis, int r, int c, int m) {
		int n = map.size();
		vis[r][c] = true;
		bool isValidRoom = true;
		if (r == 0 || r >= n - 1 || c == 0 || c >= m - 1)
			isValidRoom = false; // '.' on the boundry makes the room invalid
		for (pair<int, int> child: childs(map, r, c, m)) {
			int cr = child.first;
			int cc = child.second;
			if (!vis[cr][cc] && map[cr][cc] == '.')
				dfs(map, vis, cr, cc, m);
		}
		return isValidRoom;
	}

	int main () {
		int n,m;
		cin >> n >> m;
		vector<string> map(n);
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}
		int roomCount = 0;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.' && !visited[i][j]) {
					dfs(map, visited, i, j, m);
					roomCount++;
				}
			}
		}
		cout << roomCount << endl;
		return 0;
	}

	/*

	5 8
	########
	#......#
	####.#.#
	#......#
	########
	*/