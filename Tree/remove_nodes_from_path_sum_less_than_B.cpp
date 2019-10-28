
/************************************ Question ***************************************
Source 	: InterviewBit
Type  	: Tree
Link	: https://www.interviewbit.com/problems/remove-nodes-from-path-sum-less-than-b/
Question: Remove nodes from Path sum less than B

Given a binary tree with root node pointer A and an integer B. A complete path is defined as a path from the root to a leaf. The sum of all nodes on that path is defined as the sum of that path. You have to remove (prune the tree) all nodes which don't lie in any path with sum >= B. Note: A node can be part of multiple paths. So we have to delete it only in case when all paths from it have sum less than B. 
Input Format
The arguments given are root pointer A and an integer B.
Output Format
Return the root pointer after prunung the tree.

Constraints
1 <= Total number of nodos <= 100000
1 < = Nodes values <= 1000
1 <= B <= 10^9 

For Example
Input 1:

       1
      / \
     2   3
    / \  \
   3   4  5

   B = 7

Output 1:

      1
     / \
    2   3
    \    \
     4    5


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

bool removeNodesHavingPathSumLessThanB(TreeNode *node, int currSum, int targetSum) {
    if (node == nullptr) {
        return true;
    }
    currSum += node->val;
    if (currSum >= targetSum) {
        return true;
    }
    bool left = false;
    bool right = false;
    if (node->left != nullptr) {
        left = removeNodesHavingPathSumLessThanB(node->left, currSum, targetSum);
    }
    if (node->right != nullptr) {
        right = removeNodesHavingPathSumLessThanB(node->right, currSum, targetSum);
    }
    if (!left) {
        node->left = nullptr;
    }
    if (!right) {
        node->right = nullptr;
    }
    return left || right;
}
 
TreeNode* Solution::solve(TreeNode* root, int B) {
    bool hasAtLeastOnePath = removeNodesHavingPathSumLessThanB(root, 0, B);
    if (!hasAtLeastOnePath) {
        return nullptr;
    }
    return root;
}

