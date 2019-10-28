
/************************************ Question ***************************************
Source 	: InterviewBit
Type  	: Graph
Link	: https://www.interviewbit.com/problems/commutable-islands/
Question: Commutable Islands(connect islands wirh minimum cost)

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it. We need to find bridges with minimal cost such that all islands are connected. It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other. Input Format:
The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:
Return an integer representing the minimal cost required.
Constraints:
1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3
Examples:
Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6

Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]

Output 2:
    6

Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.


************************************* Solution ***************************************/

Note:

class union_find {
public:
    union_find(int n): parent(new int[n + 1]), size(new int[n + 1]) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    ~union_find() {
        delete parent;
        delete size;
    }
    bool isSame(int a, int b) {
        return find(a) == find(b);
    }
    
    void unite(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        
        if (size[parentA] > size[parentB]) {
            size[parentA] += size[parentB];
            parent[parentB] = parentA;
        } else {
            size[parentB] += size[parentA];
            parent[parentA] = parentB;
        }
    }
private:
    int *parent;
    int *size;
    
    int find(int v) {
        while (v != parent[v]) {
            v = parent[v];
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }
};

int Solution::solve(int A, vector<vector<int> > &B) {
    union_find uset(B.size());
    
    vector<tuple<int, int, int>> edges(B.size());
    for (int i = 0; i < B.size(); i++) {
        edges[i] = make_tuple(B[i][2], B[i][0], B[i][1]);
    }
    sort(edges.begin(), edges.end());
    
    int minCost = 0;
    int a, b, w;
    for (const auto &edge: edges) {
        tie(w, a, b) = edge;
        if (!uset.isSame(a, b)) {
            minCost += w;
            uset.unite(a, b);
        }
    }
    return minCost;
}