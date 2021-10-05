#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,m, k;
	cin >> n >> m >> k;
	vector<long long> cand(n), apt(m);
	for (int  i = 0; i < n; i++) {
		cin >> cand[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> apt[i];
	}
	sort(cand.begin(), cand.end());
	sort(apt.begin(), apt.end());

	int ci = 0;
	int ai = 0;
	int count = 0;
	while (ci < n && ai < m) {
		if (apt[ai] >= cand[ci] - k && apt[ai] <= cand[ci] + k) {
			count++;
			ci++;
			ai++;
		} else if (apt[ai] < cand[ci] - k) {
			ai++;
		} else {
			ci++;
		}
	}
	cout << count << endl;
	return 0;
}
