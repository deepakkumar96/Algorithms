#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MOD = 10e8 + 7;

bool shouldSkip(const vector<string> &grid, int n, int r, int c) {
	return grid[r - 1][c - 1] == '*' || (r == n && c == n);
}

int main () {
	int n;
	cin >> n;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	if (grid[n - 1][n - 1] == '*') {
		cout << 0;
		return 0;
	}
	vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
	dp[n][n] = 1;
	for (int r = n; r > 0; r--) {
		for (int c = n; c > 0; c--) {
			if (!shouldSkip(grid, n, r, c)) {
				if (r < n)
					dp[r][c] = (dp[r][c] + dp[r + 1][c]) % MOD; // add down
				if (c < n)
					dp[r][c] = (dp[r][c] + dp[r][c + 1]) % MOD; // add right
			}
		}
	}
	cout << dp[1][1] << endl;
	return 0;
}