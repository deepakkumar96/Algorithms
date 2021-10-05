#include <iostream>
#include <climits>

using namespace std;

#define MOD 1e9+7

int pow(long long int base, int exp) {
	long long int res = 1;
	while (exp > 0) {
		if (exp % 2 != 0) {
			res = (res * base) % ((int)MOD); //odd
		}
		base = (base * base) % ((int)MOD);
		exp /= 2;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	cout << pow(2, n) << endl;
	return 0;
}