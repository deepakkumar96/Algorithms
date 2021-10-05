#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main() {
	int t, n;
	cin >> t;
	string s;
	while (t-- > 0) {
		cin >> n;
		bool isStart = false;
		bool isBroken = false;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (s == "start" || s == "restart") {
				isStart = true;
			} else if (isStart){
				isStart = false;
			} else {
				isBroken = true;
			}
		}
		cout << (isBroken? 404: 200) << endl;
	}
	return 0;
}