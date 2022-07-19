#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

using namespace std;

const int MOD = 10e8 + 7;

vector<int> generatePossibleValues(int n, int idx, int lastVal, int m) {
	vector<int> possibleValues;
	if (idx == 0) {
			possibleValues = vector<int>(m);
			iota(possibleValues.begin(), possibleValues.end(), 1); // fill 1 to m
	} else {
		possibleValues = {lastVal};
		if (lastVal - 1 >= 1) {
			possibleValues.push_back(lastVal - 1);
		}
		if (lastVal + 1 <= m) {
			possibleValues.push_back(lastVal + 1);
		}
	}
	return possibleValues;
}

int countArraysTopDown(const vector<int> &arr, int m, int idx, int lastVal, vector<vector<int>> &dp) {
	int n = arr.size();
	if (dp[idx][lastVal] != -1) {
		//return dp[idx][lastVal];
	}
	if (idx >= n) {
		//cout << "end\n";
		return 1; //lastVal >= 1 && lastVal <= m; // reached end of array
	}
	if (arr[idx] != 0) {
		if (abs(arr[idx] - lastVal) > 1) {
			return 0; // not possible to continue	
		}
		return dp[idx][lastVal] = countArraysTopDown(arr, m, idx + 1, arr[idx], dp);
	} else {
		vector<int> possibleValues = generatePossibleValues(n, idx, lastVal, m);
		int sum = 0;
		for (int v: possibleValues) {
			sum += countArraysTopDown(arr, m, idx + 1, v, dp);
			sum %= MOD;
		}
		return dp[idx][lastVal] = sum;
	}
}

int sum(const vector<vector<int>> &dp, int r, int c, int m) {
	int res = dp[r - 1][c];
	if (c > 1)
		res = (res + dp[r - 1][c - 1]) % MOD;
	if (c < m)
		res = (res + dp[r - 1][c + 1]) % MOD;
	return res;
}

int countArraysDP(const vector<int> &arr, int m) {
	int n = arr.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		if (arr[i - 1] != 0) {
				dp[i][arr[i - 1]] = sum(dp, i, arr[i - 1], m);
				if (i == 1)
					dp[i][arr[i - 1]] = max(dp[i][arr[i - 1]], 1);
		}
		else {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = sum(dp, i, j, m);
				if (i == 1) 
					dp[i][j] = max(dp[i][j], 1);
			}
		}
	}
	return accumulate(dp[n].begin(), dp[n].end(), 0, [](int a, int b){ return (a + b) % MOD; });
}

int main () {
	int n,m;
	cin >> n >> m;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
    //vector<int> tmp(m);
    //iota(tmp.begin(), tmp.end(), 1);
    //vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	//cout << countArraysTopDown(arr, m, 0, arr[0], dp) << endl;
	cout << countArraysDP(arr, m) << endl;
	return 0;
}