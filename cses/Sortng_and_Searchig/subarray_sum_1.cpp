#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {
	int n,x, val;
	cin >> n >> x;
	map<long long, int> seenSum;
	long long sum = 0;
	long long count = 0;
	seenSum[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> val;
		sum += val;
		long long reqSum = sum - x;
		if (seenSum.find(reqSum) != seenSum.end()) {
			count += seenSum[reqSum];
		}
		seenSum[sum]++;
	}
	cout << count << endl;
	return 0;
}