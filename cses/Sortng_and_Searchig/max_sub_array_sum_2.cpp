#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main () {
	int n,a,b;
	cin n >> a >> b;
	vector<int> psum(n + 1, 0);
	psum[0] = 0;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		psum[i] = psum[i - 1] + x;
	}
	multiset<long long, greater<long long>> mset; // decereasing order
	int len = b - a;
	for (int i = 0; i < len; i++) {
		mset.insert(psum[i]);
	}
	long long maxSum = *mset.begin();
	int j = len;
	for (int i = 1; i < n; i++) {
		mset.erase(mset.find(psum[i - 1]));
		if (j < n) {
			mset.insert(psum[j]);
			j++;
		}
		maxSum = max(*mset.begin() - psum[i -1]);
	}
	cout << maxSum << endl;
	return 0;
}