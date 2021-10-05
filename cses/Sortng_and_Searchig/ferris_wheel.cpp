#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int count = 0;
	vector<long long> weights(n);
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	sort(weights.begin(), weights.end());
	vector<bool> assigned(n, false);
	int i = 0, j = n - 1;
	while (i < j) {
		if (weights[i] + weights[j] > x) {
			j--;
		} else {
			count++;
			assigned[i] = assigned[j] = true;
			i++;
			j--;
		}
	}
	count += count_if(assigned.begin(), assigned.end(), [](bool v){ return v == false;});
	cout << count << endl;
	return 0;
}