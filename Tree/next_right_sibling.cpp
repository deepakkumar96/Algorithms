/*
//find the right sibling of the given node

struct Treenode {
	int val;
	struct Treenode *left, *right, *parent;
}

    //             1
    //         2           3
    //     4       5  6          7
    // 8                          9

output :

1--> -1
2->3
8->9
5->6
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left, *right, *parent;
    TreeNode (int v) : val(v), left(nullptr), right(nullptr), parent(nullptr) { }
    TreeNode (int v, TreeNode *l, TreeNode *r, TreeNode *p) : val(v), left(l), right(r), parent(p) { }
};

// function declaration
TreeNode* buildTree();
TreeNode* findNodeWithVal(TreeNode*, int);
int getRightSiblingOf(TreeNode*);
int findLeftMostAtSameLevel(TreeNode*, int);




/*********************  MAIN METHOD *********************************/

int main() {

    int inputNode = 5;

    TreeNode *root = buildTree();

    TreeNode *node = findNodeWithVal(root, inputNode); // get reference to node with given value

    if (node != nullptr) {
        cout << node->val << " -> ";
        cout << getRightSiblingOf(node) << endl;
    } else {
        cout << "Please enter a valid node" << endl;
    }

    return 0;
}




int getRightSiblingOf(TreeNode *node)
{

    TreeNode *curr = node;
    TreeNode *prevNode = curr;
    int level = 0;

    while (curr->parent != nullptr) {
        curr = curr->parent;
        level++;
        // if valid parent
        if (curr->right != nullptr && curr->right != prevNode) {
            int leftMostChild = findLeftMostAtSameLevel(curr->right, level - 1);
            if (leftMostChild != -1) {
                return leftMostChild;
            }
        }
        prevNode= curr;
    }
    return -1;
}

int findLeftMostAtSameLevel (TreeNode *node, int level) {
    if (node == nullptr) {
        return -1;
    }
    if (level == 0) {
        return node->val;
    }
    int leftRes = findLeftMostAtSameLevel(node->left, level - 1);
    if (leftRes != -1) {
        return leftRes;
    }
    int rightRes = findLeftMostAtSameLevel(node->right, level - 1);
    return rightRes;
}


TreeNode* newNode(int n) {
    return new TreeNode(n);
}


//             1
//         2           3
//     4       5  6          7
// 8                          9

TreeNode* buildTree() {

    auto node2 = newNode(2);
    auto node3 = newNode(3);
    auto node4 = newNode(4);
    auto node5 = newNode(5);
    auto node6 = newNode(6);
    auto node7 = newNode(7);
    auto node8 = newNode(8);
    auto node9 = newNode(9);

    auto root = new TreeNode(1, node2, node3, nullptr);
    //2
    node2->parent =root;
    node2->left = node4;
    node2->right = node5;

    //3
    node3->parent = root;
    node3->left = node6;
    node3->right = node7;

    //4
    node4->parent = node2;
    node4->left = node8;

    //5
    node5->parent = node2;

    //6
    node6->parent = node3;

    //7
    node7->parent = node3;
    node7->right = node9;

    //8
    node8->parent = node4;

    //9
    node9->parent = node7;

    return root; // returning reference to node5;
}


/**
 * function to find node reference for a given value
 */
TreeNode* findNodeWithVal(TreeNode *node, int val) {
    if (!node) {
        return nullptr;
    }
    if (node->val == val) {
        return node;
    }
    auto left = findNodeWithVal(node->left, val);
    if (left) {
        return left;
    }
    return findNodeWithVal(node->right, val);
}