#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <unordered_map>

using namespace std;

optional<pair<int, int> > findPairSum(const vector<long> &arr, long target) {
	unordered_map<long, int> store;
	for (int i = 0 ; i < arr.size(); i++) {
		long rem = target - arr[i];
		if (store.find(rem) != store.end()) {
			return { {i + 1, store[rem]} };
		}
		store[arr[i]] = i + 1;
	}
	return {}; //empty		
}

optional<pair<int, int> > finPairSumTwoSum(const vector<pair<long, int> > &vals, long target) {
	int i = 0, j = vals.size() - 1;
	while (i < j) {
		long long int currSum = ((long long int) vals[i].first + vals[j].first);
		if (currSum > target) {
			j--;
		} else if (currSum < target) {
			i++;
		} else {
			return { {vals[i].second + 1, vals[j].second + 1} };
		}
	}
	return {};
}

int main() {
	long n,target,x;
	cin >> n >> target;
	vector<pair<long, int> > arr(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = {x, i};
	}
	sort(arr.begin(), arr.end());
	optional<pair<int, int> > resOpt = finPairSumTwoSum(arr, target);//findPairSum(arr, target);
	if (resOpt.has_value()) {
		cout << resOpt.value().first << " " << resOpt.value().second << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}