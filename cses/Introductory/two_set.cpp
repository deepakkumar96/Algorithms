#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &arr) {
	cout << arr.size() << endl;
	for (const auto v: arr) {
		cout << v << " ";
	}
}

int main() {
	long long int n;
	cin >> n;
	long long int sum = (n * (n + 1)) / 2;
	if (sum % 2 == 0) {
		long long int half = sum / 2;
		vector<int> firstSet, secondSet;
		long long int firstSetSum = 0;
		int a = 1, b = n;
		// 39
		// 13
		// 1 2 3 4 5 6 7 8 9 10 11 12 
		if (half % n == 0) {
			firstSetSum += n;
			b -= 1;
			firstSet.push_back(n);
		}
		while (firstSetSum < half) {
			firstSet.push_back(a);
			firstSet.push_back(b);
			firstSetSum += a + b;
			a++;
			b--;
		}
		while (a < b) {
			secondSet.push_back(a++);
			secondSet.push_back(b--);
		}
		cout << "YES" << endl;
		print(firstSet);
		cout << endl;
		print(secondSet);
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}