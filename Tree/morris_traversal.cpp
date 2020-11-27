//
// Created by deepak on 14/11/19.
//

#include <bits/stdc++.h>

using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


    vector<int> morrisInOrderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                res.push_back(current->val);
                current = current->right;
            }  else {
                TreeNode *predecessor = findPredecessor(current);
                if (predecessor->right == nullptr) { // if not predecessor not linked to current
                    // link predecessor to current node
                    predecessor->right = current;
                    current = current->left;
                } else {
                    // unlink predecessor to current
                    predecessor->right = nullptr;
                    //process current node (in case of inorder traversal)
                    res.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return res;
    }
    
    TreeNode *findPredecessor(TreeNode *root) {
        TreeNode *node = root->left;
        // `node->right != root` condition is added to avoid infinite loop in-case when predecessor is already linked to root
        while (node->right != nullptr && node->right != root) {
            node = node->right;
        }
        return node;
    }


int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    auto res = inorderTraversal(root);
    for (auto v: res){
        cout << v << " ";
    }
    return 0;
}