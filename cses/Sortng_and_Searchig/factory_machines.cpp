#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isPossibleToMake(const vector<long long int> &ms, long long int mid, long long int productsReq) {
	long long totalProducts = 0;
	for (long long int v : ms) {
		totalProducts += mid / v;
	}
	return totalProducts >= productsReq;
}

long long minTimeReqToMake(const vector<long long int> &ms, long long int sml, long long int n, long long int t) {
	long long maxTime = sml * t;
	long long minTime = t / n;

	while (minTime < maxTime) {
		long long mid = minTime + ((maxTime - minTime) / 2);
		if (isPossibleToMake(ms, mid, t)) {
			maxTime = mid;
		} else {
			minTime = mid + 1;
		}
	}
	return maxTime;
}

int main () {
	long long int n, t;
	cin >> n >> t;
	vector<long long int> ms(n, 0);
	long long int sml = INT_MAX;
	for (long long int i = 0; i < n; i++) {
		cin >> ms[i];
		sml = min(sml, ms[i]);
	}
	cout << minTimeReqToMake(ms, sml, n, t);
	return 0;
}