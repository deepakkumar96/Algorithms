#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxPagesTopDown(const vector<int> &costs, const vector<int> &pages, vector<vector<int> > &dp, int idx, int cap) {
	if (dp[idx][cap] != -1) {
		return dp[idx][cap];
	}
	if (idx >= costs.size() || cap == 0) {
		return 0;
	}
	if (costs[idx] > cap) {
		return maxPagesTopDown(costs, pages, dp, idx + 1, cap);
	}
	int including = pages[idx] + maxPagesTopDown(costs, pages, dp, idx + 1, cap - costs[idx]);
	int excluding = maxPagesTopDown(costs, pages, dp, idx + 1, cap);
	return dp[idx][cap] = max(including, excluding);
}

int maxPagesDP(const vector<int> &costs, const vector<int> &pages, int capacity) {
	vector<vector<int>> dp(costs.size() + 1, vector<int>(capacity + 1, 0));
	int n = costs.size();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= capacity; j++) {
			// current item'ss cost and page index is "i - 1"
			dp[i][j] = dp[i - 1][j];
			if (costs[i - 1] <= j && j - costs[i - 1] >= 0)
				dp[i][j] = max(dp[i - 1][j], pages[i - 1] + dp[i - 1][j - costs[i - 1]]);
		}
	}
	return dp[n][capacity];
}

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> costs(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> costs[i];
	}
	vector<int> pages(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> pages[i];
	}
	//vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
	//cout << maxPagesTopDown(costs, pages, dp, 0, x);
	cout << maxPagesDP(costs, pages, x);
	return 0;
}