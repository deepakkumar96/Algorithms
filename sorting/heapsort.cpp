#include <iostream>
#include <vector>

using namespace std;

void heap_sort(vector<int>&);
void heapify(vector<int>&, int, int);

int main () {
	
	vector<int> nums = {1, 10, 5, 100, 80, -1, 60, 30, -40};

	heap_sort(nums);

	for (int v: nums) {
		cout << v << " ";
	}

	return 0;
}

void heap_sort(vector<int> &nums) {
	int n = nums.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(nums, i, n);
    }
    int heapSize = n;
    for (int i = n - 1; i >= 0; i--) {
        swap(nums[i], nums[0]);
        heapSize--;
        heapify(nums, 0, heapSize);
    }
}

/* Max Heapify */
void heapify(vector<int> &nums, int i, int heapSize) {
	int smallest = i;
	int left  = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < heapSize && nums[smallest] < nums[left]) {
		smallest = left;
	}
	if (right < heapSize && nums[smallest] < nums[right]) {
		smallest = right;
	}
	if (smallest != i) {
		swap(nums[i], nums[smallest]);
		heapify(nums, smallest, heapSize);
	}
}