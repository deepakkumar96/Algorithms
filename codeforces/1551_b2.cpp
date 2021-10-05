#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k, x;
		cin >> n >> k;
		unordered_map<int, pair<int, vector<int> > > values;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (values[x].first < k) {
				values[x].first++;
				values[x].second.push_back(i);
			}
		}
		vector<int> colors(n, 0);
		for (const auto &p: values) {
			if (p.second.first == k) { // if freq is k
				int currColor = 1;
				for (int idx: p.second.second) {
					colors[idx] = currColor++;
				}
			}
		}
		vector<int> valuesLessThanKFreq;
		for (const auto &p: values) {
			if (p.second.first < k) { // handle freq less than K
				valuesLessThanKFreq.insert(valuesLessThanKFreq.end(), p.second.second.begin(), p.second.second.end());
			}
		}
		int valuesToColor = valuesLessThanKFreq.size() - (valuesLessThanKFreq.size() % k);
		for (int i = 0; i < valuesToColor; i += k) {
			for (int j = 1; j <= k; j++) {
				colors[valuesLessThanKFreq[i + j - 1]] = j;
			}
		}
		for(int v: colors) {
			cout << v << " ";	
		}
		cout << endl;
	}
	return 0;
}