#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string res;
	if (n == 2 || n == 3) {
		res += "NO SOLUTION";
		cout << res << endl;
		return 0;
	}
	int a = 1;
	int b = n;
	bool isLeft = true;
	for (int  i = 0; i < n; i++) {
		string val = isLeft? to_string(a++): to_string(b--);
		isLeft = !isLeft;
		if (i == n - 1) {
			res.insert(0, val + " ");
		} else {
			res += val;
			res += " ";
		}
	}
	cout << res << endl;
	return 0;
}