#include <iostream>
#include <vector>

using namespace std;

int main () {
	int n, x;
	cin >> n;
	vector<int> mods(n, 0);
	long long sum = 0;
	long long count = 0;
	mods[0]++;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		int m = (sum % n + n) % n;
		count += mods[m];
		mods[m]++;
	}
	cout << count << endl;
	return 0;
}

