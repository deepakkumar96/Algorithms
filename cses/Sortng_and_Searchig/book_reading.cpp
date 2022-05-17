#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, mx = 0, x;
	long long int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		mx = max(x, mx);
	}
	long long int res = (mx > (sum - mx)) ? (mx * 2) : sum;  
	cout << res << endl;
	return 0;
}
