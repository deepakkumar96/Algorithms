#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

#define MOD 1000000007

using namespace std;

long long g(const string &s) {
	long long count = 0;
	int currLastCharIdx = -1;
	char currLastChar = '.';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 'F') {
			if (currLastCharIdx == -1) {
				currLastChar = s[i];
				currLastCharIdx = i;
			} else if (s[i] == currLastChar){
				currLastCharIdx = i;
			} else {
				count = (count + (((currLastCharIdx + 1) * (s.length() - i)) % MOD)) % MOD;
				currLastChar = s[i];
				currLastCharIdx = i;
			}
		}
	}
	return count;
}

int main () {
	ifstream cin("/home/deepak/Documents/open_source/My/Algorithms/fc/2021/round_1/A2/input.txt");
    ofstream cout("/home/deepak/Documents/open_source/My/Algorithms/fc/2021/round_1/A2/output.txt");
	int t,n;
	cin >> t;
	string s;
	for (int c = 1; c <= t; c++){
		cin >> n;
		cin >> s;
		long long res = g(s);
		cout << "Case #" << c << ": " << res << endl;
	}
	return 0;
}