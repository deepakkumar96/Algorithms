
/************************************ Question ***************************************

Source 	: InterviewBit
Type  	: Graph
Link	: https://www.interviewbit.com/problems/shortest-distance-in-a-graph-with-two-different-weights/
Question: Shortest Distance in a graph with two different weights

Given a weighted undirected graph having A nodes, a source node C and destination node D. Find the shortest distance from C to D and if it is impossible to reach node D from C then return -1.  You are expected to do it in Time Complexity of O(A + M). Note:
There are no self-loops in the graph.
No multiple edges between two pair of vertices.
The graph may or may not be connected.
Nodes are Numbered from 0 to A-1.
Your solution will run on multiple testcases. If you are using global variables make sure to clear them.

Input Format
The first argument given is an integer A, representing the number of nodes.
The second argument given is the matrix B, where B[i][0] and B[i][1] are connected through an edge of weight B[i][2].
The third argument given is an integer C, representing the source node.
The fourth argument is an integer D, representing the destination node.

Note: B[i][2] will be either 1 or 2.
Output Format
Return the shortest distance from C to D. If it is impossible to reach node D from C then return -1.
Constraints
1 <= A <= 1e5
0 <= B[i][0], B[i][1] < A
1 <= B[i][2] <= 2
0 <= C < A
0 <= D < A
For Example
Input 1:
    A = 6
    B = [   [2, 5, 1]
            [1, 3, 1] 
            [0, 5, 2] 
            [0, 2, 2] 
            [1, 4, 1] 
            [0, 1, 1] ] 
    C = 3
    D = 2

Output 1:
    4

Explanation 1:
    The path to be followed will be:
        3 -> 1 (Edge weight : 1)
        1 -> 0 (Edge weight : 1)
        0 -> 2 (Edge weight : 2)
    Total length of path = 1 + 1 + 2 = 4.

Input 2:
    A = 5
    B = [   [0, 2, 1]
            [0, 4, 2] 
            [1, 3, 1]
            [1, 4, 1]
            [0, 1, 1] 
            [2, 4, 1]
            [3, 4, 2] 
            [1, 2, 1]  ] 
    C = 1
    D = 3

Output 2:
    1

Explanation 2:
    The path to be followed will be:
        1 -> 3 (Edge weight : 1)
    Total length of path = 1
    

************************************* Solution ***************************************/



vector<int> findShortestPathsDijsktra(int n, vector<pair<int, int>> *adj, int source) {
    vector<int> dist(n, INT_MAX);
    vector<bool> vis(n, false);

    priority_queue<pair<int, int>> pq;
    pq.push({0, source});
    dist[source] = 0;
    
    while(!pq.empty()) {
        auto u = pq.top().second;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto v: adj[u]) {
            if (v.first + dist[u] < dist[v.second]) {
                dist[v.second] = v.first + dist[u];
                pq.push({-1 * dist[v.second], v.second});
            }
        }
    }
    return dist;
}

int Solution::solve(int n, vector<vector<int> > &edges, int source, int dest) {
    vector<pair<int, int>> adj[n];
    
    for (auto edge: edges){
        int a = edge[0];
        int b = edge[1];
        int w = edge[2];
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    vector<int> distances(n);
    distances = findShortestPathsDijsktra(n, adj, source);
    for (int i = 0; i < n; i++) {
        if (distances[i] == INT_MAX) {
            distances[i] = -1;
        }
    }
    return distances[dest];
}

int solve2(int A, vector<vector<int> > &B, int C, int D) {
}


