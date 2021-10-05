#include <iostream>
#include <cmath>

using namespace std;

#define LLD long long int

LLD pow(long long int base, LLD exp) {
	long long int res = 1;
	while (exp > 0) {
		if (exp % 2 != 0) {
			res = (res * base);
		}
		base = (base * base);
		exp /= 2;
	}
	return res;
}

int findDigitAt(LLD k) {
	LLD digitsLeft = k;
	LLD totalNumbers = 9;
	LLD i = 1;
	while (digitsLeft > totalNumbers * i) {
		digitsLeft -= totalNumbers * i;
		i++;
		totalNumbers *= 10;
	}
	LLD numersRem = digitsLeft / i;
	LLD numberAtKthPos = pow(10, i - 1) + numersRem - 1;
	if (digitsLeft % i == 0) {
		return numberAtKthPos % 10; // get last digit
	} else {
		return to_string(numberAtKthPos + 1)[(digitsLeft % i) - 1] - '0'; // get rem digit in the next number
	}
}

int main() {
	int n;
	LLD k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		cout << findDigitAt(k) << endl;
	}
	return 0;
}