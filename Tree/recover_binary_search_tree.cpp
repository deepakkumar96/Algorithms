
/************************************ Question ***************************************
Source  : InterviewBit
Type    : Tree (BST)
Link    : https://www.interviewbit.com/problems/recover-binary-search-tree/
Question: Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.
 Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :
Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST  

 

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

void traverseInorder(TreeNode *node, vector<int> &traversal) {
    if (node) {
        traverseInorder(node->left, traversal);
        traversal.push_back(node->val);
        traverseInorder(node->right, traversal);
    }
}

vector<int> getInorderTraversal(TreeNode *node) {
    vector<int> inorderTraversal;
    traverseInorder(node, inorderTraversal);
    return inorderTraversal;
}

/* Returns two element which are actually swapped from the given binary tree */
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> inorderTraversal = getInorderTraversal(A);
    vector<int> swappedEle;
    for (int i = 0; i < inorderTraversal.size() - 1; i++) {
        if (inorderTraversal[i] > inorderTraversal[i + 1]) {
            swappedEle.push_back(inorderTraversal[i]);
            swappedEle.push_back(inorderTraversal[i + 1]);
        }
    }
    vector<int> swappedCopy(swappedEle);
    sort(swappedCopy.begin(), swappedCopy.end());
    for (int i = 0; i < swappedEle.size(); i++) {
        if (swappedEle[i] != swappedCopy[i]) {
            return {min(swappedEle[i], swappedCopy[i]), max(swappedEle[i], swappedCopy[i])};
        }
    }
}


