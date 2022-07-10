#include <iostream>
#include <vector>
#include <map>

using namespace std;

int shrinkWindow(const vector<int> &nums, map<int, int> &unqVals, int unqCount, int i, int k) {
	while (unqVals.size() > k) {
		int v = nums[i];
		unqVals[v]--;
		if (unqVals[v] == 0) {
			unqVals.erase(v);
		}
		i++;
	}
	return i;
}

int main () {
	int n,k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int i = 0;
	int j = 0;
	map<int, int> unqVals;
	int unqCount = 0;
	long long resCount = 0;
	while (j < n) {
		int v = nums[j];
		// mark as seen if not already
		if (unqVals.find(v) == unqVals.end()) { // if doesn't exist
			unqCount++;
			unqVals[v] = 1;
		} else {
			unqVals[v]++;
		}
		// check if window is invalid
		if (unqVals.size() > k) {
			i = shrinkWindow(nums, unqVals, unqCount, i, k);
			unqCount = unqVals.size();
		}
		resCount += j - i + 1;
		j++;
	}
	cout << resCount << endl;
	return 0;
}

/*
1 2 3 4 4 5 5 2 6


2 3 3 2 5*/