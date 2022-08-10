#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lisTopDown(const vector<int> &nums, int idx, int lastVal, unordered_map<string, int> &mem) {
	int n = nums.size();
	string memKey = to_string(idx) + "#" + to_string(lastVal);
	if (idx >= n)
		return 0;
	if (mem.find(memKey) != mem.end())
		return mem[memKey];
	int including = 0;
	if (nums[idx] > lastVal)
		including = lisTopDown(nums, idx + 1, nums[idx], mem) + 1;
	int excluding = lisTopDown(nums, idx + 1, lastVal, mem);
	return mem[memKey] = max(including, excluding);
}

int lisBottomUp(const vector<int> &nums) {
	int n = nums.size();
	vector<int> dp(n + 1, 1);
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (nums[j] < nums[i])
				dp[i + 1] = max(dp[j + 1] + 1, dp[i + 1]);
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	int maxVal = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		maxVal = max(nums[i], maxVal);
	}
	//unordered_map<string, int> mem;
	//cout << lisTopDown(nums, 0, INT_MIN, mem) << endl;
	cout << lisBottomUp(nums) << endl;
	return 0;
}