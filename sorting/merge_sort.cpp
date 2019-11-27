#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSort(vector<int>&);
void _mergeSort(vector<int>&, int, int, vector<int>&);
void merge(vector<int>&, int, int, int, vector<int>&);

int main() {
	vector<int> ar = {2, 4, 55, -1, 300, 6};
	mergeSort(ar);
	for(const auto &v: ar) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

void mergeSort(vector<int> &ar) {
	vector<int> copyAr(ar.size(), 0);
	return _mergeSort(ar, 0, ar.size() - 1, copyAr);
}

void _mergeSort(vector<int> &ar, int start, int end, vector<int> &copyAr) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		_mergeSort(ar, start, mid, copyAr);
		_mergeSort(ar, mid + 1, end, copyAr);
		merge(ar, start, mid, end, copyAr);
	}
}

void merge(vector<int> &ar, int start, int mid, int end, vector<int> &copyAr) {
	int left = start, right = mid + 1, copyIndx = start;
	while (left <= mid && right <= end) {
		if (ar[left] <= ar[right]) {
			copyAr[copyIndx] = ar[left];
			left++;
			copyIndx++;
		} else {
			copyAr[copyIndx] = ar[right];
			copyIndx++;
			right++; 
		}
	}
	
	while (left <= mid) {
		copyAr[copyIndx++] = ar[left++];
	}
	while (right <= end) {
		copyAr[copyIndx++] = ar[right++];
	}
	copy_n(copyAr.begin() + start, end - start + 1, ar.begin() + start);
}