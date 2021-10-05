#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main () {
	int n, m, val;
	cin >> n >> m;
	multiset<int> tickets;
	for (int i = 0; i < n; i++) {
		cin >> val;
		tickets.insert(val);
	}
	stringstream ss;
	for (int i = 0; i < m; i++) {
		cin >> val;
		if (tickets.empty()) {
			ss << -1 << endl;
			continue;
		}
		auto it = tickets.lower_bound(val);
		if (it != tickets.begin() && (it == tickets.end() || *it > val)) {
			it--;
		}
		if (*it > val) {
			ss << -1 << endl;
		} else {
			ss << *it << endl;
			tickets.erase(it);
		}
	}
	cout << ss.str();
	return 0;
}