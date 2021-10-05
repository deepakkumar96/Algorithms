#include <iostream>
#include <climits>
#include <vector>

using namespace std;


int main() {
	int n, currVal;
	cin >> n;
	long long int count = 0;
	int lastNum = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> currVal;
		if (currVal < lastNum) {
			count += lastNum - currVal;
		}
		lastNum = max(lastNum, currVal);
	}
	cout << count << endl;
	return 0;
}