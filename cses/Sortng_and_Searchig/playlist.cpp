#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int shrinkWindow(const vector<int> &vals, unordered_map<int, int> &seen, int beg, int end) {
    for (int i = beg; i <= end; i++) {
        seen.erase(vals[i]);
    }
    return end + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    unordered_map<int, int> seen;
    int windowBeg = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int v = vals[i];
        if (seen.find(v) != seen.end()) {
            windowBeg = shrinkWindow(vals, seen, windowBeg, seen[v]);
        }
        seen.insert({v, i});
        maxLen = max(i - windowBeg + 1, maxLen);
    }
    cout << maxLen << endl;
    return 0;
}