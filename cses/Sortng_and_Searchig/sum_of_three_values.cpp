#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int> &p, int x) {
	return p.first < x;
}

int main () {
	int n,x,inputVal;
	cin >> n >> x;
	vector<pair<int, int>> nums;
	for (int i = 0; i < n; i++) {
		cin >> inputVal;
		nums.push_back({inputVal, i});
	}
	sort(nums.begin(), nums.end());
	bool isFound = false;
	for (int i = 0; i < n - 2; i ++) {
		for (int j = i + 1; j < n - 1; j++) {
			int reqVal = x - nums[i].first - nums[j].first;
			// cout << ":" << j + 1 << " "  << endl;
			auto it = lower_bound(nums.begin() + j + 1, nums.end(), reqVal, cmp);
			if (it != nums.end() && it->first == reqVal) {
				cout << nums[i].second + 1 << " " << nums[j].second + 1 << " " << nums[(it - nums.begin())].second + 1 << endl;
				isFound = true;
				break; 
			}
		}
		if (isFound) {
			break;
		}
	}
	if (!isFound) {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}