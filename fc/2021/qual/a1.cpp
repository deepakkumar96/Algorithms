#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

int maxFreq(const unordered_map<char, int> &freq) {
	int maxCount = 0;
	for (auto p: freq) {
		maxCount = max(p.second, maxCount);
	}
	return maxCount;
}

int main() {
	ifstream cin("/home/deepak/Documents/open_source/My/Algorithms/fc/2021/qual/input.txt");
    ofstream cout("/home/deepak/Documents/open_source/My/Algorithms/fc/2021/qual/output.txt");
	int n;
	cin >> n;
	string s;
	int caseCount = 1;
	while (n-- > 0) {
		cin >> s;
		int vowelCount = 0;
		int consCount = 0;
		unordered_map<char, int> vowelFreq, consFreq;
		for (char c : s) {
			if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
				vowelFreq[c]++;
				vowelCount++;
			} else {
				consFreq[c]++;
				consCount++;
			}
		}
		int maxVowelCount = maxFreq(vowelFreq);
		int maxConsCount  = maxFreq(consFreq);

		int x = vowelCount + ((consCount - maxConsCount) * 2);
		int y = consCount + ((vowelCount - maxVowelCount) * 2);
		cout << "Case #" << (caseCount++) << ": " << min(x, y) << endl;
	}
}