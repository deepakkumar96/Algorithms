#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
	return min(a, min(b, c));
}

int editDistanceTopDown(const string &s, const string &t, int i, int j, vector<vector<int>> &dp) {
	if (dp[i][j] != -1)
		return dp[i][j];
	if (i >= s.size())
		return t.size() - j;
	if (j >= t.size())
		return s.size() - i;
	if (s[i] == t[j]) 
		return dp[i][j] = editDistanceTopDown(s, t, i + 1, j + 1, dp);
	int res = 1 + min(editDistanceTopDown(s, t, i, j + 1, dp),
		   editDistanceTopDown(s, t, i + 1, j, dp),
		   editDistanceTopDown(s, t, i + 1, j + 1, dp));
	return dp[i][j] = res;
	
}

int editDiatanceDP(const string &s, const string &t) {
	int m = s.size();
	int n = t.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= n; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
		}
	}
	return dp[m][n];
}

int main () {
	string s,t;
	cin >> s >> t;
	//vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
	cout << editDiatanceDP(s, t);
	return 0;
}

/*
LOVE
MOVIE
sunday
saturday
*/