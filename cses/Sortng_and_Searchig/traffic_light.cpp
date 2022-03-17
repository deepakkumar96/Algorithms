#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main() {
    int x, n, p;
    cin >> x >> n;
    set<int> lights{0, x};
    multiset<int> dis{x};
    for (int i = 0; i < n; i++) {
        cin >> p;
        lights.insert(p);
        auto it = lights.find(p);
        auto prevIt = prev(it);
        auto nextIt = next(it);
        dis.erase(dis.find(*nextIt - *prevIt));
        dis.insert(*it - *prevIt);
        dis.insert(*nextIt - *it);
        cout << (*dis.rbegin()) << " ";
    }
    return 0;
}