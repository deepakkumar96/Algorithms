#include <iostream>
#include <climits>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

string getRes(const string &s, const unordered_map<char, int> &freq, int oddFreqCount) {
	if (s.size() % 2 == 0 && oddFreqCount > 0) {
		return "NO SOLUTION";
	}
	if (s.size() % 2 != 0 && oddFreqCount != 1) {
		return "NO SOLUTION";
	}
	list<char> res;
	if (s.size() % 2 != 0) { // if odd length
		for (const auto &pair: freq) {
			char letter = pair.first;
			int count = pair.second;
			if (count % 2 != 0) {
				for (int i = 0; i < count; i++) {
					res.push_back(letter);
				}
				break;
			}
		}
	}
	for (const auto &pair: freq) {
		char letter = pair.first;
		int count = pair.second;
		if (count % 2 == 0) {
			for (int i = 0; i < (count / 2); i++) {
				res.push_back(letter);
				res.push_front(letter);
			}
		}
	}
	string str = "";
	for (char c : res) {
		str += c;
	}
	return str;
}

int main() {
	string s;
	cin >> s;
	unordered_map<char, int> freq;
	for (char c : s) {
		freq[c]++;
	}
	int oddFreqCount = count_if(freq.begin(), freq.end(), [&](const pair<char, int> &pair){ return pair.second % 2 != 0;});
	cout << getRes(s, freq, oddFreqCount) << endl;
	return 0;
}