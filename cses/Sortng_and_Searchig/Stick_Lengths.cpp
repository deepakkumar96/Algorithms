#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMedian(const vector<int> &arr) {
	int n = arr.size();
	if (n % 2 != 0) {
		return arr[n / 2];
	} else {
		int left = arr[(n - 1) / 2];
		int right = arr[(n + 1) / 2];
		return ((left + right) / 2);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int median = findMedian(arr);
	long long int cost = 0;
	for (int v : arr) {
		cost += abs(v - median);
	}
	cout << cost << endl;
	return 0;
}