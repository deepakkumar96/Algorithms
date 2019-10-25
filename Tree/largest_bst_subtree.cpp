
/************************************ Question ***************************************
Largest BST Subtree
Given a binary tree. Find the size of largest subtree which is a Binary Search Tree (BST), where largest means subtree with the largest number of nodes in it. Note: A subtree must include all of its descendants. For Example
Input 1:
                     10
                    / \
                   5  15
                  / \   \ 
                 1   8   7
Output 1:
    3
    Explanation 1:
        Largest BST subtree is
                            5
                           / \
                          1   8

Input 2:
                5
               / \
              3   8
             / \ / \
            1  4 7  9
Output 2:
     7
     Explanation 2:
        Given binary tree itself is BST.
*/

/************************************* Solution *******************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
	
}