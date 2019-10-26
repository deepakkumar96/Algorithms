/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


int maxIncreasingSeq2(TreeNode *node, int lastCount, int lastNodeVal, int &maxRes) {
    if (node == nullptr) {
        return lastCount;
    }
    lastCount = (node->val) == lastNodeVal ? lastCount + 1: 1;
    maxRes = max(maxRes, lastCount);
    
    int left = maxIncreasingSeq2(node->left, lastCount, node->val + 1, maxRes);
    int right = maxIncreasingSeq2(node->right, lastCount, node->val + 1, maxRes);
    return max(lastCount, max(left, right));
}

int Solution::solve(TreeNode* A) {
    if (A == nullptr) {
        return 0;
    }
    int maxRes = 0;
     maxIncreasingSeq2(A, 0, A->val, maxRes);
    return maxRes;
}


/*
int maxIncreasingSeq(TreeNode *node, int lastCount, int lastNodeVal) {
    if (node == nullptr) {
        return lastCount;
    }
    int newCountForSubtree = (node->val > lastNodeVal) ? lastCount + 1 : 0;
    int leftCount = 0;
    if (node->left != nullptr) {
        leftCount = maxIncreasingSeq(node->left, newCountForSubtree + (node->left->val > node->val)? 1: 0, node->val);
    }
    int rightCount = 0;
    if (node->right != nullptr) {
        rightCount = maxIncreasingSeq(node->right,  newCountForSubtree + (node->left->val > node->val)? 1: 0, node->val);
    }
    
    int currentCount = (node->val > lastNodeVal)? lastCount + 1: lastCount; + 
    
    
    return max(currentCount, max(leftCount, rightCount));
} */