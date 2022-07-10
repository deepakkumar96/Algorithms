#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;


int main () {
	int n,a,b;
	cin >> n >> a >> b;
	vector<long long> psum(n, 0);
	//psum[0] = 0;
	int x;
    long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
        sum += x;
		psum[i] = sum;
	}
	multiset<long long, greater<>> mset; // decereasing order
	int i = 0;
	int j = a - 1;
	int k = b - 1;

	for (int l = j; l <= min(n,k); l++) {
		mset.insert(psum[l]);
	}
	long long maxSum = *mset.begin();
	i++;
	k++;
	//cout << max
	while ((n - i + 1) >= a) {
		mset.erase(mset.find(psum[j]));	
		if (k < n) {
			mset.insert(psum[k]);
			k++;
		}
        if (!mset.empty())
		    maxSum = max(*mset.begin() - psum[i - 1], maxSum);
		i++;
		j++;
	}
	cout << maxSum << endl;
	return 0;
}