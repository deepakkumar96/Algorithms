#include<iostream>
#include<algorithm>

using namespace std;

void towerOfHanoiRec(int n, int from, int aux, int to, string &res) {
	if (n == 1) {
		res += to_string(from) + " " + to_string(to) + "\n";
	} else {
		towerOfHanoiRec(n - 1, from , to, aux, res);
		res += to_string(from) + " " + to_string(to) + "\n";
		towerOfHanoiRec(n - 1, aux, from, to, res);
	}
}

int main() {
	int n;
	cin >> n;
	string res = "";
	towerOfHanoiRec(n, 1, 2, 3, res);
	cout << count_if(res.begin(), res.end(), [](char c){ return c == '\n';}) << endl;
	cout << res << endl;
	return 0;
}