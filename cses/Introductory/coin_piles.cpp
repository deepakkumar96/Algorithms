#include <iostream>
#include <climits>

using namespace std;

int main() {
	int t;
	long long int a, b;
	cin >> t;
	while (t-- > 0) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			cout << "YES" << endl;
		} else if (a == 0 || b == 0) {
			cout << "NO" << endl;
		} else if ((a + b) % 3 == 0 && max(a, b) <= (min(a, b) * 2)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}