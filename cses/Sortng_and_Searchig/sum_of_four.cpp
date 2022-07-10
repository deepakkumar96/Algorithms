#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int n,x, val;
	cin >> n >> x;
	vector<pair<int, int>> nums;
	for (int i = 0; i < n; i++) {
		cin >> val;
		nums.push_back({val, i + 1});
	}
	sort(nums.begin(), nums.end());
	bool isFound = false;
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 1; j < n - 2; j++) {
			int low = j + 1;
			int high = n - 1;
			int reqVal = x - nums[i].first - nums[j].first;
			while (low < high) {
				int sum = nums[low].first + nums[high].first;
				if (/*i != low && i != high && j != low && j != high &&*/ sum == reqVal) {
					cout << nums[i].second << " " << nums[j].second << " " << nums[low].second << " " << nums[high].second << endl;
					isFound = true;
					break;
				} else if (sum < reqVal) {
					low ++;
				} else {
					high--;
				}
			}
			if (isFound) break;
		}
		if (isFound) break;
	}
	if (!isFound) cout << "IMPOSSIBLE" << endl;
	return 0;
}