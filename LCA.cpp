#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Function to find the Lowest Common Ancestor
Node* LCA(Node* root, Node* p, Node* q) {

    // Base case: tree is empty or current node is p or q
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Search for p or q in the left subtree
    Node* left = LCA(root->left, p, q);

    // Search for p or q in the right subtree
    Node* right = LCA(root->right, p, q);

    // If both sides return a node, current root is the LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise, return the non-null result
    // If both are NULL, this also returns NULL
    return (left != NULL) ? left : right;
}

int main() {
    // Create the binary tree
    //          3
    //         / \
    //        5   1
    //       / \ / \
    //      6  2 0  8
    //        / \
    //       7   4

    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    // Select the two target nodes
    Node* p = root->left;                // Node 5
    Node* q = root->left->right->right;  // Node 4

    // Find the LCA
    Node* ans = LCA(root, p, q);

    if (ans != NULL) {
        cout << "Lowest Common Ancestor = " << ans->val << endl;
    }

    return 0;
}
