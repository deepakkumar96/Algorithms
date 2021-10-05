#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	long long int x;
	cin >> n;
	vector<long long int> values(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		values[i] = x;
	}
	sort(values.begin(), values.end());
	int count = 0;
	int i = 0;
	while (i < n) {
		count++;
		while (i < (n - 1) && values[i] == values[i + 1]) {
			i++;
		}
		if (i == (n - 2) && values[n-2] == values[n-1]) {
			i += 2;
		} else {
			i++;
		}
	}
	cout << count << endl;
	return 0;
}