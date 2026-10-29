
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == NULL)
        return 0;

    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Insert node and balance the AVL tree
Node* insert(Node* node, int value) {
    if (node == NULL) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;

        return newNode;
    }

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Display preorder traversal
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Display inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Display AVL tree in tree shape
void display(Node* root, int space = 0) {
    if (root == NULL)
        return;

    space += 7;

    display(root->right, space);

    cout << endl;

    for (int i = 7; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    display(root->left, space);
}

int main() {
    Node* root = NULL;

    int values[] = {
        110, 10, 20, 120, 100, 40,
        60, 50, 70, 80, 30, 90
    };

    int n = sizeof(values) / sizeof(values[0]);

    // Insert all values into the AVL tree
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Display preorder traversal
    cout << "Preorder Traversal: ";
    preorder(root);

    // Display inorder traversal
    cout << "\nInorder Traversal: ";
    inorder(root);

    // Display root and balance factor
    cout << "\nRoot Node: " << root->data;
    cout << "\nRoot Balance Factor: " << getBalance(root);

    // Display the AVL tree structure
    cout << "\n\nAVL Tree Structure:\n";
    display(root);

    return 0;
}

