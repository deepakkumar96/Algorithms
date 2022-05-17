#include <iostream>
#inclide <vector>

using namespace std;

int main() {
	int n, mx, x;
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		mx = max(x, mx);
	}
	long long int res = (mx > (sum - mx)) ? (mx * 2) : sum;  
	cout << res << endl;
	return 0;
}