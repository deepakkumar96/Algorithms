#include<iostream>
#include<vector>
#include<climits>
#include<map>

using namespace std;

using namespace std;

const int MOD = 10e8 + 7;

map<int, int> dp;

int numOfWayTopDown(const vector<int> &coins, int x) {
	if (x == 0) {
		return 1;
	}
	if (dp.find(x) != dp.end()) {
		return dp[x];
	}
	int sum = 0;
	for (int c: coins) {
		if (x - c >= 0) {
			sum = (sum + numOfWayTopDown(coins, x - c)) % MOD;
		}
	}
	dp[x] = sum;
	return sum;
}


int numOfWayBottomUp(const vector<int> &coins, int x) {
	vector<int> dp(x + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		for (int c: coins) {
			if (i - c >= 0) {
				dp[i] = ((long long)dp[i] + dp[i - c]) % MOD;
			}
		}
	}
	return dp[x];
}

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	cout << numOfWayBottomUp(coins, x) << endl;
	return 0;
}