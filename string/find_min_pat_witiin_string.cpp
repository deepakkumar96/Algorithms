/*
Given two strings string1 and string2, the task is to find the smallest substring in string1 containing all characters of string2 efficiently.

Input: string = “this is a test string”, pattern = “tist”
Output: Minimum window is “t stri”
Explanation: “t stri” contains all the characters of pattern.

map : pattern
o - 1
r - 1
k - 1

start 0
end 0

pattrnLen = 3
windowLen = 3

map : current window
k - 2
o - 1
r - 1

Input: string = “geekksforgeeks”, pattern = “ork”
Output: Minimum window is “ksfor”

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// function declaration
string findSmallestStringHavingPattern(string, string);
int shrinkCurrentWindow(string&,unordered_map<char, int>&,
                        unordered_map<char, int>&,int,int);

int main() {
    string input = "geekksforgeeks";
    string pattern = "ork";
    
    cout << "running..." << endl;

    cout << findSmallestStringHavingPattern(input, pattern);
    return 0;
}

string findSmallestStringHavingPattern(string str, string pat) {
    unordered_map<char, int> patMap, windowMap;
    
    for (const auto c: pat) {
        patMap[c]++;
    }
    
    int patternLen = pat.length();
    int windowLen = 0;
    int beg = 0;
    
    int resLen = INT_MAX;
    int resStart = 0, resEnd = 0;
    
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        
        if (patMap.find(c) != patMap.end()) { // if c exist in pattern
            windowMap[c]++;
            if (windowMap[c] <= patMap[c]) {
                windowLen++;
            }
        }
        if (windowLen == patternLen) { // match found
            //skring window or beg pointer
            beg = shrinkCurrentWindow(str, patMap, windowMap, beg, i);
            
            int newWindowLen = i - beg + 1;
            if (newWindowLen < resLen) {
                resStart = beg;
                resLen = newWindowLen;
            }
        }
    }
    return str.substr(resStart, resLen);
}

int shrinkCurrentWindow(string &str, unordered_map<char, int> &patMap,
                       unordered_map<char, int> &windowMap, int beg, int end) {            
    while (beg < end) {
        char c = str[beg];
        if (patMap.find(c) == patMap.end()) { // if c not in window
            beg++;
        } else if (windowMap[c] > patMap[c]) { // if freq of c greater that required
            windowMap[c]--;
            beg++;
        } else {
            break; // not possible to shrink window
        }
    }
    return beg;
}

