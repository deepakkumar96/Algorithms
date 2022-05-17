#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int t, dr, dl;
	cin >> t;
	vector<pair<int, int>> tasks;
	while (t-- > 0) {
		cin >> dr >> dl;
		tasks.push_back({dr, dl});
	}
	sort(tasks.begin(), tasks.end());
	long long time = 0;
	long long int total = 0;
	for (const auto &task: tasks) {
		time += task.first;
		total += task.second - time;
	}
	cout << total << endl;
	return 0;
}

