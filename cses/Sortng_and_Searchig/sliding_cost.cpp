#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

class MedianSet{
private:
	multiset<int, greater<int>> firstHalf; // containing first half in decending order, 
	multiset<int> secondHalf; // containing second half
	long long firstHalfSum = 0;
	long long secondHalfSum = 0;

	void balance() {
		if (secondHalf.size() == firstHalf.size()) {
			return;
		}
		if (firstHalf.size() > secondHalf.size() + 1) {
			secondHalfSum += *firstHalf.begin();
			firstHalfSum -= *firstHalf.begin();
			secondHalf.insert(*firstHalf.begin());
			firstHalf.erase(firstHalf.find(*firstHalf.begin()));
		} else if (firstHalf.size() + 1 < secondHalf.size()) {
			firstHalfSum += *secondHalf.begin();
			secondHalfSum -= *secondHalf.begin();
			firstHalf.insert(*secondHalf.begin());
			secondHalf.erase(secondHalf.find(*secondHalf.begin()));
		}
	}
public:
	void remove(int v) {
		if (firstHalf.find(v) != firstHalf.end()) {
			firstHalfSum -= v;
			firstHalf.erase(firstHalf.find(v));
		} else {
			secondHalf.erase(secondHalf.find(v));
			secondHalfSum -= v;
		}
		balance();
	}

	void add(int v) {
		if (v <= getMedian()) {
			firstHalf.insert(v);
			firstHalfSum += v;
		} else {
			secondHalf.insert(v);
			secondHalfSum += v;
		}
		balance();
	}

	int getMedian() {
		if (firstHalf.size() == secondHalf.size()) {
			return min(*firstHalf.begin(), *secondHalf.begin());
		}
		return firstHalf.size() > secondHalf.size() ? *firstHalf.begin() : *secondHalf.begin();
	}

	long long getCost() {
		long long firstHalfCost = ((long long)getMedian() * firstHalf.size()) - firstHalfSum;
		long long secondHalfCost = secondHalfSum - ((long long) getMedian() * secondHalf.size());
		return firstHalfCost + secondHalfCost;
	}
};

vector<long long> slidingCost(const vector<int> &nums, int k) {
	MedianSet mset;
	for (int i = 0; i < k; i++) {	
		mset.add(nums[i]);
	}
	int i = 0;
	vector<long long> res;
	res.push_back(mset.getCost());
	for (int j = k; j < nums.size(); j++) {
		mset.remove(nums[i]);
		mset.add(nums[j]);
		res.push_back(mset.getCost());
		i++;
	}
	return res;
}

int main () {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (long long v : slidingCost(nums, k)) {
		cout << v << " ";
	}
	return 0;
}