#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b;
	cin >> n;
	vector<pair<int, int>> movies;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		movies.push_back({a, b});
	}
	sort(movies.begin(), movies.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
		return p1.second < p2.second;
	});
	int currEnd = 0;
	int count = 0;
	for (const auto& pr: movies) {
		//cout << pr.first << " " << pr.second << endl;
		if (pr.first >= currEnd) {
			currEnd = pr.second;
			count++;
		}
	}
	cout << count << endl;
	return 0;
}