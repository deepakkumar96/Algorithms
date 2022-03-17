#include <iostream>
#include <vector>

using namespace std;

bool between(int a, int b, int x) {
    return x > a && x < b;
}

int main () {
    int n,m;
    cin >> n >> m;
    vector<int> pos(n + 1);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    pos[0] = 0;
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) {
            rounds++;
        }
    }
    int a,b;
    //cout<<rounds<<endl;
    while (m-- > 0) {
        cin >> a >> b;
        swap(arr[a], arr[b]);
        swap(pos[arr[a]], pos[arr[b]]);
        unordered_set<pair<int, int> > changedPairs = {
            {a, b}, {a - 1, a}, {a + 1, a}, {b - 1, b}, {b + 1, b}
        };
        for (pair<int, int> p: changedPairs) {
            int sml = min(p.frist, p.second);
            int lrg = max(p.first, p.second);
            if (pos[sml] > pos[lrg]) {
                rounds++;
            }
        }
    }
    return 0;
}

/*
4 2 1 5 3

2 3
4 1 2 5 3 | 2

1 5
3 1 2 5 4 | 

20 5
14 2 3 10 8 9 1 19 4 15 5 17 13 16 7 11 6 12 18 20
13 13
10 1
12 20
4 15
8 6


5 1
4 2 1 5 3
2 2
1 5
2 3

*/