#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int countSteps(int n, vector<int> &dp) {
	if (dp[n] != INT_MAX) return dp[n];
	if (n < 0) {
		return INT_MAX;
	}
	if (n == 0) {
		return 0;
	}
	int m = n;
	int steps = INT_MAX;
	while (m != 0) {
		if (m % 10 != 0) {
			int req = countSteps(n - (m % 10), dp) + 1;
			if (req != INT_MAX)
				steps = min(req, steps);
		}
		m /= 10;
	}
	return dp[n] = steps;
}

int countStepsBottomUp(int n) {
	vector<int> dp(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int m = i;
		int steps = INT_MAX;
		while (m != 0) {
			if (m % 10 != 0) {
				steps = min(dp[i - (m % 10)] + 1, steps);
			}
			m /= 10;
		}
		dp[i] = steps;
	}
	return dp[n];
}

int main () {
	int n;
	cin >> n;
	cout << countStepsBottomUp(n);
	return 0;
}