//
// Created by deepaksonava on 22/04/22.
//

#include<iostream>
#include <set>

using namespace std;

struct P {
    int x,y;
    bool has = false;

    bool operator< (const P &other) const {
        return abs(x - y) > abs(other.x - other.y);
    }
};

void dump(set<P> set1);

int main () {
    set<P> s;
    P p1 = {0, 9};
    P p2 = {4, 5};
    P p3 = {5, 20};
    P p4 = {1, 100};
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    dump(s);
    p4.has = true;
    cout << (s.find(p4) != s.end()) << endl;
    s.erase(p4);
    dump(s);
    return 0;
}

void dump(set<P> s) {
    for (P p: s) {
        cout << p.x << "-" << p.y << (p.has ? "T" : "F") <<  ", ";
    }
    cout << endl;
}
