#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

// Preorder Traversal (Root -> Left -> Right)
void preorder(Node* node){
    if(node==NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(Node* node){
    if(node==NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(Node* node){
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {
    // Create a simple binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}
