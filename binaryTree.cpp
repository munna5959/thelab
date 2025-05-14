#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) { // Constructor to initialize node
        data = value;
        left = right = nullptr;
    }
};

// Insert function (adds nodes to the tree)
Node* insert(Node* root, int value) {
    if (root == nullptr) 
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Simple traversal functions
void inorder(Node* root) { // Left → Root → Right
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) { // Root → Left → Right
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) { // Left → Right → Root
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Main function
int main() {
    Node* root = nullptr;

    // Insert nodes easily
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) root = insert(root, v);

    cout << "Inorder traversal: "; inorder(root); cout << endl;
    cout << "Preorder traversal: "; preorder(root); cout << endl;
    cout << "Postorder traversal: "; postorder(root); cout << endl;

    return 0;
}
