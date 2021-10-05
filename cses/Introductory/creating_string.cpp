#include<iostream>
#include<string>
#include<unordered_map>
#include<set>

using namespace std;

unordered_map<char, int> createFreqMap(const string &str) {
	unordered_map<char, int> freq;
	for (char c : str) {
		freq[c]++;
	}
	return freq;
}

void permute(unordered_map<char, int> &freq, int rem, string prefix, set<string> &res) {
	if (rem == 0) {
		res.insert(prefix);
	} else {
		for (pair<char, int> p: freq) {
			char c = p.first;
			if (freq[c] > 0) {
				freq[c]--;
				permute(freq, rem - 1, prefix + c, res);
				freq[c]++;
			}
		}
	}
}

int main() {
	string str;
	cin >> str;
	set<string> res;
	unordered_map<char, int> freq = createFreqMap(str);
	permute(freq, str.length(), "", res);
	cout << res.size() << endl;
	for (const string &s: res) {
		cout << s << endl;
	}
	return 0;
}