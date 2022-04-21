#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

void removeIfPossible(int startInvl, multiset<pair<int, int>> &coll, set<int> &emptyRooms) {
	set<pair<int, int> >::iterator remIt = coll.lower_bound({startInvl, 0});
	auto begIt = coll.begin();
	while (begIt != remIt) {
		emptyRooms.insert(( *begIt).second);
		begIt = coll.erase(begIt);
	}
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> invl;
	int a,b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		invl.push_back({a, b});
	}
	sort(invl.begin(), invl.end());
	set<int> emptyRooms;
	int roomCnt = 1;
	int minReq = 1;
	vector<int> res;
	multiset<pair<int, int>> coll;
	for (auto p: invl) {
		int x, y;
		tie(x, y) = p;
		removeIfPossible(x, coll, emptyRooms);
        int alcRoom;
        if (!emptyRooms.empty()) {
            auto it = emptyRooms.begin();
        	alcRoom = *it;
            emptyRooms.erase(it);
        	minReq = max(alcRoom, minReq);
        } else {
        	alcRoom = roomCnt++;
        	minReq = max(alcRoom, minReq);
        }
        coll.insert({y, alcRoom});
        res.push_back(alcRoom);
	}
	cout << minReq << endl;
	for (int v: res) {
		cout << v << " ";
	}
	return 0;
}