#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	string seq;
	while (t-- > 0) {
		cin >> seq;

		int roundOpenCount = 0;
		int squareOpenCount = 0;
		int resCount = 0;
		for (char c : seq) {
			if (c == '(') {
				roundOpenCount++;
			} else if (c == '[') {
				squareOpenCount++;
			} else if (c == ')') {
				if (roundOpenCount > 0) {
					roundOpenCount--;
					resCount++;
				}
			} else {
				if (squareOpenCount > 0) {
					squareOpenCount--;
					resCount++;
				}
			}
		}
		cout << resCount << endl;
	}
	return 0;
}