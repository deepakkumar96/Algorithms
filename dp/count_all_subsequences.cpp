
/************************************ Question ***************************************

Source 	: ...
Type  	: String | DP
Link	: <link-to-question>
Question: Count occurance of a string as a subsequence

Given a two strings S and T, find count of distinct occurrences of T in S as a subsequence.

************************************* Solution ***************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countSubSeq(const string &str, const string &seq, int strIndx, int seqIndx) {
	if (seqIndx >= seq.length()) {
		return 1;
	}
	if (strIndx > str.length()) {
		return 0;
	}
	if (str[strIndx] == seq[seqIndx]) {
		return countSubSeq(str, seq, strIndx + 1, seqIndx + 1) + countSubSeq(str, seq, strIndx + 1, seqIndx);
	} else {
		return countSubSeq(str, seq, strIndx + 1, seqIndx);
	}
}

int countSubsequences(const string &s, const string &t) {
	return countSubSeq(s, t, 0, 0);
}

int main() {
	string s = "vvowovov";
	string t = "vvovv";
	cout << countSubsequences(s, t) << endl;
	return 0;
}

