
/************************************ Question ***************************************
Source 	: InterviewBit
Type  	: Tree
Link	: https://www.interviewbit.com/problems/difference-between-odd-and-even-levels/
Question: Difference between odd and even levels

Given a binary tree of integers. Find the difference between the sum of nodes at odd level and sum of nodes at even level. Note: Consider the level of root node as 1. Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9 
For Example
Input 1:
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8 
Output 1:
    10
    Sum of nodes at odd level = 23
    Sum of ndoes at even level = 13

Input 2:
            1
           /  \
          2    10
           \
            4
Output 2:
    -7
    Sum of nodes at odd level = 5
    Sum of ndoes at even level = 12

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

int _parityDiff(TreeNode *node, int level, int sum) {
    if (node == nullptr) {
        return sum;
    }
    sum += (level & 1)? node->val: (-1 * node->val); // add if level is odd else subtract
    int leftSum = _parityDiff(node->left, level + 1, sum);
    return _parityDiff(node->right, level + 1, leftSum);
} 
 
int parityDiff(TreeNode *node) {
    return _parityDiff(node, 1, 0);
}
 
int Solution::solve(TreeNode* A) {
    return parityDiff(A);
}


