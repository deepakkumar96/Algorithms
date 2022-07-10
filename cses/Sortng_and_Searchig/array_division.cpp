#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

/*bool isPossible(const vector<int> &nums, int k, long long mid) {
	long long currSum = 0;
	int i = 0;
	while (k > 0 && i < nums.size()) {
		if (nums[i] > mid) {
			return false;
		}
		if (currSum + nums[i] > mid) {
			//start new subarray
			k--;
			currSum = 0;
		} 
		currSum += nums[i];
		i++;
	}
	if (i < nums.size() - 1) {
		currSum += accumulate(nums.begin() + i + 1, nums.end(), 0);
	}
	return  k == 1 && currSum <= mid;
}*/

bool isPossible(const vector<int> &nums, int k, long long mid) {
	long long sum = 0;
	int groups = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > mid) {
			return false;
		}
		if (sum + nums[i] > mid) {
			sum = 0;
			groups++;
		}
		sum += nums[i];
	}
	if (sum > 0) {
		groups++;
	}
	return groups <= k;
}


int main () {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	long long sum = 0;
	int minVal = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sum += nums[i];
		minVal = min(nums[i], minVal);
	}
	long long low = minVal;
	long long high = sum;
	while (low < high) {
		long long mid = low + ((high - low) / 2);
		if (isPossible(nums, k, mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << high << endl;
	return 0;
}