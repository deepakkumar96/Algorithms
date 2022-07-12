#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

const int MOD = 10e8 + 7;
unordered_map<int, int> cache;

int diceCombinationsTopDown(int n) {
	if (n < 0) {
		return 0;
	} else if (n < 2) {
		return 1;
	} else if (cache.find(n) != cache.end()) {
		return cache[n];
	} else {
		long long sum = 0;
		for (int i = 1; i <= min(n, 6); i++) {
			if (n - i >= 0) {
				sum = (sum + diceCombinationsTopDown(n - i)) % MOD;
			}
		}
		cache[n] = sum;
		return sum;
	}
}

int diceCombinationBottomUp(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= min(i, 6); j++) {
			dp[i] += dp[i - j];
		}
	}
	return dp[n];
}

int main () {
	int n;
	cin >> n;
	cout << diceCombinationsTopDown(n);
	return 0;
}