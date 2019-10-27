
/************************************ Question ***************************************
Source 	: InterviewBit
Type  	: Tree
Link	: https://www.interviewbit.com/problems/node-distance-c-in-binary-tree/
Question: Node distance C in binary tree

Given a binary tree of integers. All nodes in the binary tree have distinct values. You are given an integer B. You have to find all the nodes that are at a distance of exactly C from the node containing value B. Return an array of integers consisting all the nodes that are C distance from node containing value B. Note:
You may return the nodes in any order.
Your solution will run on multiple test cases, if you are using global variables make sure to clear every time .
Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= Node values <= 10^9 
0 <= B <= 10^9
0 <= C <= 100
For Example
Input 1:
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8 

     B = 3
     C = 3
Output 1:
    [4, 5]

Input 2:
            1
           /  \
          2    3
           \
            4
             \
              5
        B = 4
        C = 1
Output 2:
    [2, 5]


************************************* Solution ***************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void _findChildParentMapping(TreeNode *node, TreeNode *lastNode, unordered_map<TreeNode*, TreeNode*> &childParentMapping) {
    if (node != nullptr) {
        if (lastNode != nullptr) {
            childParentMapping[node] = lastNode;
        }
        _findChildParentMapping(node->left, node, childParentMapping);
        _findChildParentMapping(node->right, node, childParentMapping);
    }
} 

/* Creates a mapping of child-parent relation ship for a binary tree */
unordered_map<TreeNode*, TreeNode*> findChildParentMapping(TreeNode *root) {
    unordered_map<TreeNode*, TreeNode*> childParentMapping;
    _findChildParentMapping(root, nullptr, childParentMapping);
    return childParentMapping;
}

vector<int> bfs(TreeNode *node, int target, int targetDistance, unordered_map<TreeNode*, TreeNode*> &childParentMapping) {
    queue<TreeNode*> que;
    unordered_set<int> vis;
    unordered_map<int, int> dis;
    que.push(node);
    vis.insert(node->val);
    dis[node->val] = 0;
    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        vector<TreeNode*> childs;
        if (top->left != nullptr) {
            childs.push_back(top->left);
        }
        if (top->right != nullptr) {
            childs.push_back(top->right);
        }
        if (childParentMapping.find(top) != childParentMapping.end()) {
            childs.push_back(childParentMapping[top]);
        }
        for (auto child: childs) {
            if (vis.find(child->val) == vis.end()) {
                vis.insert(child->val);
                dis[child->val] += dis[top->val] + 1;
                que.push(child);
            }
        }
    }
    // find all the node which has target distance
    vector<int> res;
    for (auto p: dis) {
        if (p.second == targetDistance) {
            res.push_back(p.first);
        }
    }
    return res;
} 

TreeNode* findNodeRef(TreeNode *node, int target) {
    if (node == NULL) {
        return NULL;
    }
    if (node->val == target) {
        return node;
    }
    auto left = findNodeRef(node->left, target);
    if (left != nullptr) {
        return left;
    } else {
        return findNodeRef(node->right, target);
    }
}
vector<int> Solution::solve(TreeNode* A, int B, int C) {
    auto targetNode = findNodeRef(A, B);
    auto childParentMapping = findChildParentMapping(A);
    return bfs(targetNode, B, C, childParentMapping);
}

