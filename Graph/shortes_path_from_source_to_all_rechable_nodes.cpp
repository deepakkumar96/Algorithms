
/************************************ Question ***************************************
Source 	: InterviewBit
Type  	: Graph
Link	: 
Question: Shortes path from source to all nodes

Given a weighted undirected graph having A nodes and M weighted edges, and a source node C. You have to find an integer array D of size A such that:

=> D[i] : Shortest distance form the C node to node i. 
=> If node i is not reachable from C then -1.

Note:
There are no self-loops in the graph.
No multiple edges between two pair of vertices.
The graph may or may not be connected.
Nodes are numbered from 0 to A-1.
Your solution will run on multiple testcases. If you are using global variables make sure to clear them.

Input Format
The first argument given is an integer A, representing the number of nodes.
The second argument given is the matrix B of size M x 3, where nodes B[i][0] and B[i][1] are connected with an edge of weight B[i][2].
The third argument given is an integer C.
Output Format
Return the integer array D.
Constraints
1 <= A <= 1e5
0 <= B[i][0],B[i][1] < A
0 <= B[i][2] <= 1e3;
0 <= C < A
For Example
Input 1:
    A = 6
    B = [   [0, 4, 9]
            [3, 4, 6] 
            [1, 2, 1] 
            [2, 5, 1] 
            [2, 4, 5] 
            [0, 3, 7] 
            [0, 1, 1] 
            [4, 5, 7] 
            [0, 5, 1] ] 
    C = 4
Output 1:
    D = [7, 6, 5, 6, 0, 6]

Input 2:
    A = 5
    B = [   [0, 3, 4]
            [2, 3, 3] 
            [0, 1, 9] 
            [3, 4, 10] 
            [1, 3, 8]  ] 
    C = 4
Output 2:
    D = [14, 18, 13, 10, 0]


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

vector<int> Solution::solve(int n, vector<vector<int> > &edges, int source) {
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
    return distances;
}


