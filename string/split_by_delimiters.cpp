/*
Given Char array and list of delimeters, split the array using the delimeters

char[] arr = {'a', 'b', 'c', '-', 'd', 'e', '/','a', ':', 'b', 'c','*', 'd', 'e'};
char[] delimiters = {'/', '*', ':', '-'}

output:
{"abc", "de", "a", "bc", "de"}
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> split(vector<char> inputStr, vector<char> delimiters);

int main() {

    vector<char> input = {'a', 'b', 'c', '-', 'd', 'e', '/','a', ':', 'b', 'c','*', 'd', 'e'};
    vector<char> delimiters = {'/', '*', ':', '-'};

    auto words = split(input, delimiters);
    for (const string &w: words) {
        cout << w << " ";
    }
    return 0;
}

vector<string> split(vector<char> inputStr, vector<char> delimiters) {
    unordered_set<char> delim;
    for (char d: delimiters) {
        delim.insert(d);
    }
    vector<string> res;
    string currStr = "";
    for (char c: inputStr) {
        if (delim.find(c) == delim.end()) { // if not delimiter
            currStr += c;
        } else {
            res.push_back(currStr);
            currStr = "";
        }
    }
    if (!currStr.empty()) {
        res.push_back(currStr);
    }
    return res;
}
