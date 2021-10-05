#include<iostream>

using namespace std;

int main() {
	int t;
	long long int a, b;
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%lld %lld", &a, &b);
		long long int count = ((a/2) * (b/2));// even-to-even count
		count += ((a + 1) / 2) * ((b + 1) / 2);
		printf("%lld\n", count);
	}
	return 0;
}