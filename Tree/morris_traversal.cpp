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


    TreeNode* findInOrderPredecessor(TreeNode *node) {
        auto itr = node->left;
        while (itr->right != nullptr && itr->right != node) {
            itr = itr->right;
        }
        return itr;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> preorderTraversal;
        auto currNode = root;
        while (currNode != nullptr) {
            if (currNode->left == nullptr) {
                preorderTraversal.push_back(currNode->val);
                currNode = currNode->right;
            } else {
                auto predecessor = findInOrderPredecessor(currNode);
                if (predecessor->right == nullptr) {
                    predecessor->right = currNode;
                    currNode = currNode->left;
                } else {
                    predecessor->right = nullptr;
                    preorderTraversal.push_back(currNode->val);
                    currNode = currNode->right;
                }
            }
        }
        return preorderTraversal;
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