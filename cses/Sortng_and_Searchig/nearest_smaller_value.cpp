#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main () {
	int n,v;
	cin >> n;
	stack<pair<int, int>> stk;
	for (int i = 0; i < n; i++) {
		cin >> v;
		while (!stk.empty() && stk.top().first >= v) {
			stk.pop();
		}
		if (stk.empty()) {
			cout << "0";
		} else {
			cout << stk.top().second;
		}
		stk.push({v, i + 1});
		if (i != n - 1) {
			cout << " ";
		}
	}
	return 0;
}