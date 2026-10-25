#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

void DFS(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";  // Visit root
    DFS(root->left);            // Go left
    DFS(root->right);           // Go right
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "DFS: ";
    DFS(root);

    return 0;
}