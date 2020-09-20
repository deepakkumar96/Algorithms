#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge_sort(vector<int>&);
void merge_sort(vector<int>&, int, int, vector<int>&);
void merge(vector<int>&, int, int, int, vector<int>&);

int main () {
	vector<int> nums = {1, 10, 5, 100, 80, -1, 60, 30, -40};
	merge_sort(nums);
	for (int v : nums) {
		cout << v << " ";
	}
	return 0;
}


void merge_sort(vector<int> &nums) {
    vector<int> aux(nums.size(), 0); 
	merge_sort(nums, 0, (int)nums.size() - 1, aux);
}

void merge_sort(vector<int> &nums, int l, int r, vector<int> &copy) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		merge_sort(nums, l, mid, copy);
		merge_sort(nums, mid + 1, r, copy);
		merge(nums, l, mid, r, copy);
	}
}

void merge(vector<int> &nums, int l, int mid, int r, vector<int> &aux) {
	int cStart = 0;
	int m = l;
	int p = mid + 1;

	while (m <= mid && p <= r) {
		if (nums[m] < nums[p]) {
			aux[cStart++] = nums[m++];
		} else {
			aux[cStart++] =  nums[p++];
		}
	}
	while (m <= mid) {
        aux[cStart++] = nums[m++];
    }
    while (p <= r) {
        aux[cStart++] = nums[p++];
    }
    copy_n(aux.begin(), r - l + 1, nums.begin() + l);
}