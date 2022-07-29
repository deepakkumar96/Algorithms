#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
#include <sstream>

using namespace std;

void sumCountTopDown(const vector<int> &nums, int i, int runningSum, vector<vector<int>> &dp) {
	int n = nums.size();
	if (i > n || dp[i][runningSum] != -1)
		return;
	if (i == n) {
		dp[i][runningSum] = 1;
		return;
	}
	int newSum = runningSum + nums[i];
	dp[i][runningSum] = 1;
	dp[i][newSum] = 1; // mark this state as visisted
	sumCountTopDown(nums, i + 1, newSum, dp);
	sumCountTopDown(nums, i + 1, runningSum, dp);
}

void solveTopDown(const vector<int> &nums, vector<vector<int>> &dp, int n, int maxSum) {
	sumCountTopDown(nums, 0, 0, dp);
	vector<int> res;
	for (int i = 1; i <= maxSum; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[j][i] != -1) {
				res.push_back(i);
				break; 
			}
		}
	}
	cout << res.size() << endl;
	for (int v : res) 
		cout << v << " ";
}

void sumCountBottomUp(const vector<int> &nums, 
					 int sum) {
	int n = nums.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
	for (int i = 1; i <= n; i++) {
		dp[i][nums[i - 1]] = true;
		for (int j = 1; j <= sum; j++) {
			if (dp[i - 1][j]) {
				dp[i][j] = true;
				if (nums[i - 1] + j <= sum)
					dp[i][j + nums[i - 1]] = true;
			}
		}
	}
	stringstream ss;
	int resCnt = 0;
	for (int i = 1; i <= sum; i++) {
		if (dp[n][i]) {
			resCnt++;
			ss << i << " ";
		}
	}
	cout << resCnt << endl;
	cout << ss.str();
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	int maxSum = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		maxSum += nums[i];
	}
	//vector<vector<int>> dp(n + 1, vector<int>(maxSum + 1, -1));
	//solveTopDown(nums, dp, n, maxSum); // top-down
	sumCountBottomUp(nums, maxSum);
	return 0;
}