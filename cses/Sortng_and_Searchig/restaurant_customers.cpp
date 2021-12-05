#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int n, a, l;
	cin >> n;
	vector<pair<int, int>> time;
	for (int i = 0; i < n; i++) {
		cin >> a >> l;
		time.push_back({a, false});
		time.push_back({l, true});
	}
	sort(time.begin(), time.end());
	int runningSum = 0;
	int maxCustomers = 0;
	for (pair<int, int> pr: time) {
		if (!pr.second) { // arrival
			runningSum++;
		} else {
			runningSum--;
		}
		maxCustomers = max(runningSum, maxCustomers);
	}
	cout << maxCustomers << endl;
	return 0;
}
