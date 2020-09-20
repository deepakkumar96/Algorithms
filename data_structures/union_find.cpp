#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class UnionFind {
public:
	UnionFind(int n);
	~UnionFind();
	int find(int);
	bool same(int, int);
	void unite(int, int);
private:
	int *parent;
	int *size;
};



int main() {
	UnionFind uf(6);
	uf.unite(0, 4);
	uf.unite(1, 4);
	uf.unite(2, 5);
    uf.unite(2, 3);

	assert(uf.same(0, 1) == true);
	assert(uf.same(0, 5) == false);
	assert(uf.same(3, 4) == false);
	assert(uf.same(3, 5) == true);
	return 0;
}

UnionFind::UnionFind(int n) {
	parent = new int[n];
	size   = new int[n];

	for (int i = 0; i < n; i++) {
		parent[i] = i;
		size[i] = 1	;
	}
}

UnionFind::~UnionFind() {
	cout << "realising allocated memory" << endl;
	delete[] parent;
	delete[] size;
}


int UnionFind::find(int x) {
	while (parent[x] != x) {
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

bool UnionFind::same(int a, int b) {
	return find(a) == find(b);
}

void UnionFind::unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	if (size[b] > size[a]) {
		swap(a, b);
	}
	parent[b] = a;
	size[a] += size[b];
}

