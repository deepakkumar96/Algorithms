
/************************************ Question ***************************************

Source 	: InterviewBit
Type  	: Graph
Link	: https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
Question: Possibility of finishing all courses given pre-requisites (Finding Cycle in a graph)

There are a total of A courses you have to take, labeled from 1 to A.  Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2]. Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses. Input Format:
The first argument of input contains an integer A, representing the number of courses.
The second argument of input contains an integer array, B.
The third argument of input contains an integer array, C.
Output Format:
Return a boolean value:
    1 : If it is possible to complete all the courses.
    0 : If it is not possible to complete all the courses.
Constraints:
1 <= A <= 6e4
1 <= length(B) = length(C) <= 1e5
1 <= B[i], C[i] <= A
Example:
Input 1:
    A = 3
    B = [1, 2]
    C = [2, 3]

Output 1:
    1

Explanation 1:
    It is possible to complete the courses in the following order:
        1 -> 2 -> 3

Input 2:
    A = 2
    B = [1, 2]
    C = [2, 1]

Output 2:
    0

Explanation 2:
    It is not possible to complete all the courses.


************************************* Solution ***************************************/


enum nodecolor {
    WHITE,
    GRAY,
    BLACK
};

bool hasCycleHelper(vector<int> *adj, int u, vector<nodecolor> &state) {
    state[u] = GRAY;
    for (auto v: adj[u]) {
        if (state[v] == WHITE && hasCycleHelper(adj, v, state)) {
            return true;
        } else if (state[v] == GRAY) {
            return true;
        }
    }
    state[u] = BLACK;
    return false;
}

bool hasCycle(vector<int> *adj, int n) {
    vector<nodecolor> state(n + 1, WHITE);
    for (int i = 1; i <= n; i++) {
        if (state[i] == WHITE && hasCycleHelper(adj, i, state)) {
            return true;
        }
    }
    return false;
}

int Solution::solve(int n, vector<int> &node, vector<int> &depend) {
    vector<int> adj[n + 1];
    for (int i = 0; i < node.size(); i++) {
        adj[node[i]].push_back(depend[i]);
    }
    return !hasCycle(adj, n); // possible to arrange if there is no cycle
}


