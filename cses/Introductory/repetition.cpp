#include <iostream>
#include <climits>

using namespace std;

int main() {
	string s;
	cin >> s;
	unsigned int maxLen = 1;
	unsigned int start = 0;
	unsigned int i = 1;
	while (i < s.length()) {
		while (s[i] == s[i - 1]) {
			i++;
		}
		maxLen = max(i - start, maxLen);
		start = i;
		i++; // move to next index
	}
	cout << maxLen << endl;
	return 0;
}