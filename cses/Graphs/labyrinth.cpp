#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
Gets direction from jumping a to b
*/
char getDirection(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) 
		return b.first > a.first ? 'D' : 'U';
	return b.second > a.second ? 'R' : 'L';
}

vector<pair<int, int>> childs(int i, int j, int n, int m) {
	vector<pair<int, int>> res;
	if (i - 1 >= 0)
		res.push_back({i - 1, j});
	if (i + 1 < n)
		res.push_back({i + 1, j});
	if (j - 1 >= 0)
		res.push_back({i, j - 1});
	if (j + 1 < m)
		res.push_back({i, j + 1});
	return res;
}

string shortestPathBfs(const vector<string> &map, pair<int, int> start, pair<int, int> end) {
	int n = map.size();
	int m = map[0].size();
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	queue<pair<int, int> > que;
	que.push(start);
	vis[start.first][start.second] = true;
	bool isFound = false;
	while (!que.empty()) {
		auto node = que.front();
		int i = node.first;
		int j = node.second;
		que.pop();
		if (node == end) {
			isFound = true;
			break;
		}
		for (auto child: childs(i, j, n, m)) {
			int ci = child.first;
			int cj = child.second;
			if (!vis[ci][cj] && map[ci][cj] == '.' || map[ci][cj] == 'B') {
				vis[ci][cj] = true;
				parent[ci][cj] = {i, j};
				que.push(child);
			}
		}
	}
	if (!isFound) return "NO";
	pair<int, int> pathIdx = end;
	string resPath = "";
	while (pathIdx != start) {
		auto p = parent[pathIdx.first][pathIdx.second];
		resPath += getDirection(p, pathIdx);
		pathIdx = p;	
	}
	reverse(resPath.begin(), resPath.end());
	return resPath;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> map(n);
	pair<int, int> start;
	pair<int, int> end;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		size_t idx = map[i].find('A');
		if (idx != string::npos)
			start = {i, idx};
		size_t endIdx = map[i].find('B');
		if (endIdx != string::npos)
			end = {i, endIdx};
	}
	auto res = shortestPathBfs(map, start, end);
	if (res == "NO") cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << res.size() << endl;
		cout << res << endl; 
	}
	return 0;
}


/*
5 8
########
#.A...##
#.##.#B#
#.....##
########
*/