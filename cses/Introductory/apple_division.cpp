#include<iostream>
#include<vector>

using namespace std;

long long int minDiff(const vector<int> &weights, int idx, long long int grpOne, long long int grpTwo) {
	if (idx >= weights.size()) {
		return abs(grpOne - grpTwo);
	} else {
		return min(
			minDiff(weights, idx + 1, grpOne + weights[idx], grpTwo),
			minDiff(weights, idx + 1, grpOne, grpTwo + weights[idx])
		);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> weights(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	if (n == 1) {
		cout << weights[0] << endl;
	} else {
		cout << minDiff(weights, 0, 0L, 0L) << endl;
	}
	return 0;
}