/************************************ Question ***************************************

Source 	: Daily Interview Pro
Type  	: Strings
Link	: 
Question:



************************************* Solution ***************************************/

// 1. Sorting O(nlogn)

// 2. Union-Find O(nlogn)

// 3. Hashing O(n) ans O(n) space


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> findLongestIncrSeq(vector<int> &nums) {
	unordered_set<int> hash;
	for (const auto &v: nums) {
		hash.insert(v);
	}
	vector<int> maxSeq;
	for (int i = 0; i < nums.size(); i++) {
		if (hash.find(nums[i] - 1) == hash.end()) {
			int counter = 1;
			vector<int> currSeq;
			currSeq.push_back(nums[i]);
			while (hash.find(nums[i] + counter) != hash.end()) {
				currSeq.push_back(nums[i] + counter);
				counter++;
			}
			if (maxSeq.size() < currSeq.size()) {
				maxSeq = currSeq;
			}
		}
	}
	return maxSeq;
}


int main() {
	
	vector<int> nums = {5, 2, 99, 30, 4, 1, 100, 6};
	auto res = findLongestIncrSeq(nums);
	cout << "longest increasing sequence : " << res.size() << endl;
	for (const auto &v: res) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}


