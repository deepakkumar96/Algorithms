#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	assert(n >= 1);
	vector<int> arr(n);
	long long int maxSum = INT_MIN;
	long long int currSum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxSum = max((long long int)arr[i], maxSum);
	}
	for (int i = 0; i < arr.size(); i++) {
		currSum = currSum + x;
		maxSum = max(currSum, maxSum);
		currSum = max(currSum, (long long int)0);
	}
	cout << maxSum << endl;
	return 0;
}