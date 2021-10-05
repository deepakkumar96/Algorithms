#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Model {
public:
	int outfit;
	bool hasChanged = false;

	Model() { }
	Model(int outfit) {
		this->outfit = outfit;
		this->hasChanged = false;
	}
};


unordered_map<int, int> getCurrentOutfitMap(const vector<Model> &models) {
	unordered_map<int, int> currOutfitMap;
	for (int i = 0; i < models.size(); i++) {
		currOutfitMap[models[i].outfit]++;
	}
	return currOutfitMap;
}

int assignOutfit(unordered_map<int, int> &currentOutfitMap, unordered_map<int, int> &requiredOutfitMap) {
	int assignedOutfit = 0;
	for (pair<int, int> p: requiredOutfitMap) {
		int outfit = p.first; 
		int count = p.second;
		if (currentOutfitMap.find(outfit) == currentOutfitMap.end() || requiredOutfitMap[outfit] > currentOutfitMap[outfit]) {
			assignedOutfit = outfit;
			requiredOutfitMap[outfit]--;
			if (requiredOutfitMap[outfit] < 1) { // remove if coutn reaches zero
				requiredOutfitMap.erase(outfit);
			}
			break;
		}
	}
	return assignedOutfit;
}

int main() {
	int T, n, m, s;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++) {
		cin >> n >> m;
		vector<Model> models(m);

		for (int i = 0; i < m; i++) { // initial outfit
			cin >> s;
			models[i] = Model(s); // adding  Si
		}
		unordered_map<int, int> outfitReq;
		int p;
		int cost = 0;
		while(n--) { // iterate over all rounds
			for (int i = 0; i < m; i++) { //Pi of each round
				cin >> p;
				outfitReq[p]++;
			}
			unordered_map<int, int> currentOutfitsMap = getCurrentOutfitMap(models);
			for (int i = 0; i < models.size(); i++) {
				int currOutfit = models[i].outfit;
				if (outfitReq.find(currOutfit) != outfitReq.end()) { // if next round contains same outfit
					outfitReq[currOutfit]--;
					if (outfitReq[currOutfit] < 1) { // remove if coutn reaches zero
						outfitReq.erase(currOutfit);
					}
				} else if (!models[i].hasChanged) { 
					models[i].hasChanged = true;
					models[i] = assignOutfit(currentOutfitsMap, outfitReq);
				} else {
					cost++;
					models[i] = assignOutfit(currentOutfitsMap, outfitReq);
				}
			}
			outfitReq.clear();
		}
		cout << "Case #" << testCase << ": " << cost << endl; 
	}
	return 0;
}