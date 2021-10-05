// https://codeforces.com/problemset/problem/1559/D1
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
	vector<int> parent;
	vector<int> size;

public:	
	UnionFind(int n) {
		parent.resize(n + 1);
		for (int i = 0; i < n + 1; i++) {
			parent[i] = i;
		}
		size.resize(n + 1, 1);
	}

	bool isInSame(int a, int b) {
		return find(a) == find(b);
	}

	void unite(int a, int b) {
		int pa = find(a); // pa = parent of a
		int pb = find(b); // pb = parent of v
		if (pa != pb) {
			if (size[pb] > size[pa]) {
				swap(pa, pb); // now size of a is bigger than b 
			}
			parent[pb] = pa;
			size[pa] += size[pb];
		}
	}

	int find(int x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
};


int main () {
	int n, m1, m2;
	cin >> n >> m1 >> m2;

	UnionFind uf1(n);
	int u, v;
	for (int i = 0; i < m1; i++) {
		cin >> u >> v;
		uf1.unite(u, v);
	}
	UnionFind uf2(n);
	for (int i = 0; i < m2; i++) {
		cin >> u >> v;
		uf2.unite(u, v);
	}
	vector<pair<int, int> > res;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!uf1.isInSame(i, j) && !uf2.isInSame(i, j)) {
				res.push_back({i, j});
				uf1.unite(i, j);
				uf2.unite(i, j);
			}
		}
	}
	cout << res.size() << endl;
	for (pair<int, int> edge: res) {
		cout << edge.first << " " << edge.second << endl;
	}
	return 0;
}