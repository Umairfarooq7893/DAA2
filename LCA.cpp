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

Node* LCA(Node* root, int n1, int n2) {
    if (root == nullptr)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

   if (left != nullptr && right != nullptr)
        return root;

    if (left != nullptr)
        return left;

    return right;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node* ans = LCA(root, 4, 5);

    if (ans != nullptr)
        cout << "LCA = " << ans->data;

    return 0;
}
