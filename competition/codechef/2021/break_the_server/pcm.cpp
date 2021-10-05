#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main() {
	int t;
	cin >> t;
	string s;
	while (t-- > 0) {
		cin >> s;
		unordered_set<char> ss;
		for (char c : s) {
			ss.insert(c);
		}
		cout << (ss.size() == 3? "YES": "NO") << endl;
	}
	return 0;
}