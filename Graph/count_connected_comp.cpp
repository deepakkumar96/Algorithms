class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        forward_list<int> adj[n];

        for (const vector &edge: edges) {
        	int u = edge[0];
        	int v = edge[1];
        	adj[u].push_front(v);
        	adj[v].push_front(u);
        }

        int compCount = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
        	if (!vis[i]) {
        		compCount++;
        		dfs(adj, vis, i);
        	}
        }
        return compCount;
    }

    void dfs(forward_list<int> *adj, vector<bool> &vis, int u) {
    	vis[u] = true;
    	for (const int &v: adj[u]) {
    		if (!vis[v]) {
    			dfs(adj, vis, v);
    		}
    	}
    }
};




#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    unordered_map<char, int> mapping;

    int maxRepeatingCount = 0;
    int windowStartIdx = 0;

    for (int i = 0; i < str.length(); i++) {
    	char c = str[i];
    	mapping[c]++;
    	maxRepeatingCount =	max(maxLength, mapping[c]);
    	
    	int currWindowSize = i - windowStartIdx + 1;
    	if (currWindowSize - maxRepeatingCount > k) {
    		mapping[str[windowStartIdx]]--;
    		if (mapping[str[windowStartIdx]] <= 0) {
    			mapping.erase(str[windowStartIdx]);
    		}
    		windowStartIdx++;
    	}
    	maxLength = max(maxLength, i - windowStartIdx + 1);
    }

    return maxLength;
  }
};



#include <iostream>
#include <vector>

using namespace std;

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0;
    int start = 0;
    int zeroCount = 0;

    for (int i = 0; i < arr.size(); i++) {
    	if (arr[i] == 0) {
    		zeroCount++;
    	}
    	if (zeroCount > k) {
    		start++;
    	}
    	maxLength = max(maxLength, i - start + 1);
    }
    return maxLength;
  }
};
