#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<algorithm>
#include<numeric>

using namespace std;

const int MOD = 10e8 + 7;

unordered_map<string, int> dp;

int numOfWayTopDown(const vector<int> &coins, int x, int idx) {
	auto key = [](int n, int idx) { return to_string(n) + "#" + to_string(idx);};
	if (dp.find(key(x, idx)) != dp.end()) {
		return dp[key(x, idx)];
	}
	if (x < 0) {
		return 0;
	}
	if (x == 0) {
		return 1;
	}
	int sum = 0;
	for (int i = idx; i < coins.size(); i++) {
		if (x - coins[i] >= 0) {
			sum = (sum + numOfWayTopDown(coins, x - coins[i], i)) % MOD;
		}
	}
	dp[key(x, idx)] = sum;
	return sum;
}


int numOfWayBottomUp(const vector<int> &coins, int x) {
	vector<vector<int>> dp(x + 1, vector<int>(coins.size(), 0));
	//init x = 0
	for (int i = 0; i < coins.size(); i++) {
		dp[0][i] = 1;
	}
	for (int v = 1; v <= x; v++) {
		for (int j = 0; j < coins.size(); j++) {
			if (v - coins[j] >= 0) {
				dp[v][j] = dp[v - coins[j]][j];
			}
			if (j > 0)
				dp[v][j] = (dp[v][j] + dp[v][j - 1]) % MOD;
		}
	}
	// for(vector<int> vs: dp){ for(int v: vs) cout << v << " "; cout << endl;}
	return dp[x][coins.size() - 1];
}

int numOfWayBottomUpSingleDimension(const vector<int> &coins, int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int c: coins) {
		for (int w = 1; w <= n; w++) {
			if (w - c >= 0) {
				dp[w] += dp[w - c];
				dp[w] %= MOD;
			}
		}
	}
	// for(vector<int> vs: dp){ for(int v: vs) cout << v << " "; cout << endl;}
	return dp[n];
}

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());
	//cout << numOfWayTopDown(coins, x, 0) << endl;
	cout << numOfWayBottomUpSingleDimension(coins, x) << endl;
	return 0;
}