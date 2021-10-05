#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string res;
	if (n == 2 || n == 3) {
		res.append("NO SOLUTION");
		cout << res << endl;
		return 0;
	}
	for (int i = 2; i <=n ;) {
		res.append(to_string(i));
		res.append(" ");
		i += 2;
	}
	for (int i = 1; i <= n;) {
		res.append(to_string(i));
		res.append(" ");
		i += 2;
	}
	cout << res << endl;
	return 0;
}