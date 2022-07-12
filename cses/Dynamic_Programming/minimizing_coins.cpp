#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

map<int, int> dp;


int minWaysTopDown(const vector<int> &coins, int x) {
	if (dp.find(x) != dp.end()) {
		return dp[x]; 
	}
	if (x < 0) {
		return INT_MAX;
	}
	if (x == 0) {
		return 0;
	}
	int minWay = INT_MAX;
	for (int v : coins) {
		int count = minWaysTopDown(coins, x - v);
		if (count != INT_MAX)
			minWay = min(minWaysTopDown(coins, x - v) + 1, minWay);
	}
	dp[x] = minWay;
	return dp[x];
}
//1 5 7
int minWaysBottomUp(const vector<int> &coins, int x) {
	vector<int> dp(x + 1, 0);
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		int minCount = INT_MAX;
		for (int v : coins) {
			if (i - v >= 0 && dp[i - v] != INT_MAX) 
				minCount = min(dp[i - v] + 1, minCount);
		}
		dp[i] = minCount;
	}
	return dp[x];
}

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> coins(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	int count = minWaysBottomUp(coins, x);
	cout << ((count != INT_MAX) ? count : -1);
	return 0;
}