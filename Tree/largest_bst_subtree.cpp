
/************************************ Question ***************************************

Source	: InterviewBit
Type  	: Tree
Link	: https://www.interviewbit.com/problems/largest-bst-subtree
Question: Largest BST Subtree

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

int findSize(TreeNode* root){
    if(not root) {
        return 0;
    }
    return findSize(root->left) + findSize(root->right) + 1;
}

bool isBst(TreeNode* root, int minVal, int maxVal){
    if(not root)  {
        return true;
    }
    if(root->val<minVal or root->val>maxVal) {
        return false;
    }
    return isBst(root->left, minVal, root->val) and isBst(root->right, root->val, maxVal);
}


int findLargestBst(TreeNode* root){
    if(not root)  {
        return 0;
    }
    if(isBst(root, INT_MIN, INT_MAX)) {
        return findSize(root);
    }
    return max(findLargestBst(root->left), findLargestBst(root->right));
}

int Solution::solve(TreeNode *root) {
	/*auto maxSubTree = findMaxSubTree(root, INT_MIN, INT_MAX);
	return maxSubTree.second;*/	
	return findLargestBst(root);
}