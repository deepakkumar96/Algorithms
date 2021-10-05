#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// returns count of ele present in A but not in B
int difference(const unordered_set<char> &a, const unordered_set<char> &b) {
	int count = 0;
	for (char c : a) {
		if (b.find(c) == b.end()) {
			count++;
		}
	}
	return count;
}

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++) {
			cin >> words[i];
		}
		unordered_map<string, unordered_set<char> > suffixMapping;
		for (string word: words) {
			string suffix = word.substr(1, word.length());
			suffixMapping[suffix].insert(word[0]);
		}

		int resCount = 0;
		for (auto pairOne: suffixMapping) {
			for (auto pairTwo: suffixMapping) {
				if (pairOne.first != pairTwo.first) { // if not same words
					int aDiffB = difference(pairOne.second, pairTwo.second);
					int bDiffA = difference(pairTwo.second, pairOne.second);
					resCount += aDiffB * bDiffA;
				}
			}
		}
		cout << resCount << endl;
	}
	return 0;
}