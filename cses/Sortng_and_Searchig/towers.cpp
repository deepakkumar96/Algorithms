#include <iostream>
#include <set>

using namespace std;

int main() {
    int n,x;
    cin >> n;
    multiset<int> towers;
    for (int i = 0; i < n; i++) {
        cin >> x;
        auto it = towers.upper_bound(x);
        if (it != towers.end()) {
            towers.erase(it);    
        }
        towers.insert(x);
    }
    cout << towers.size() << endl;
    return 0;
}