#include<iostream>

using namespace std;

int main() {
	
	long long int n;
	cin >> n;
	string res = "";
	while (n != 1) {
		res.append(to_string(n));
		res += " ";
		if (n % 2 == 0) {
			n /= 2;
		} else {
			n = (3 * n) + 1;
		}
	}
	cout << res << 1 << endl;
	return 0;
}