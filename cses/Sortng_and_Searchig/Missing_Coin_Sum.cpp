#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long long int res = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > res) {
			break;
		}
		res += arr[i];
	}
	cout << res << endl;
	return 0;
}