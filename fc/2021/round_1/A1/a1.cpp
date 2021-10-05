#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream cin("/home/deepak/Documents/open_source/My/Algorithms/fc/2021/round_1/A1/weak_typing_chapter_1_input.txt");
    ofstream cout("/home/deepak/Documents/open_source/My/Algorithms/fc/2021/round_1/A1/output.txt");
	int t, n;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cin >> n;
		string word = "";
		char letter;
		for (int i = 0; i < n; i++) {
			cin >> letter;
			if (letter != 'F') {
				word += letter;
			}
		}
		auto it = unique(word.begin(), word.end());
		word.erase(it, word.end());
		cout << "Case #" << c << ": " << max(0, static_cast<int>(word.length() - 1)) << endl;
	}
	return 0;
}