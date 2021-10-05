#include<iostream>
#include<cassert>
#include<vector>

using namespace std;


bool isValid(int n, int row, int col, vector<bool> &cols, vector<bool> &ld, vector<bool> &rd, const vector<string> &board) {
	return board[row][col] != '*' && !cols[col] && !ld[col - row + n - 1] && !rd[row + col];
}

void place(int n, int row, int col, vector<bool> &cols, vector<bool> &ld, vector<bool> &rd) {
	cols[col] = ld[col - row + n - 1] = rd[row + col] = true;
}

void unplace(int n, int row, int col, vector<bool> &cols, vector<bool> &ld, vector<bool> &rd) {
	cols[col] = ld[col - row + n - 1] = rd[row + col] = false;
}

int waysToPlaceNQueen(int n, int row, vector<bool> &cols, vector<bool> &ld, vector<bool> &rd, const vector<string> &board) {
	if (row == n) {
		return 1;
	}
	int count = 0;
	for (int col = 0; col < n; col++) {
		if (isValid(n, row, col, cols, ld, rd, board)) {
			place(n, row, col, cols, ld, rd);
			count += waysToPlaceNQueen(n, row + 1, cols, ld, rd, board);
			unplace(n, row, col, cols, ld, rd);
		}
	}
	return count;
}


int main() {
	int sz = 8;
	vector<bool> placedCl(sz, false);
	vector<bool> placedLd(2 * sz + 1, false);
	vector<bool> placedRd(2 * sz + 1, false);
	vector<string> board;
	string input;
	for (int i = 0; i < sz; i++) {
		cin >> input;
		board.push_back(input);
	}
	assert(placedCl.size() == 8);
	cout << waysToPlaceNQueen(sz, 0, placedCl, placedLd, placedRd, board) << endl;
	return 0;
}