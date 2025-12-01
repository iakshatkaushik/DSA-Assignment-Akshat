#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root && root->data != key) {
        root = key < root->data ? root->left : root->right;
    }
    return root;
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* n) {
    if (n->right) return minNode(n->right);
    Node* succ = NULL;
    while (root) {
        if (n->data < root->data) {
            succ = root;
            root = root->left;
        } else if (n->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* n) {
    if (n->left) return maxNode(n->left);
    Node* pred = NULL;
    while (root) {
        if (n->data > root->data) {
            pred = root;
            root = root->right;
        } else if (n->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    Node* n = searchRec(root, 50);
    cout << "Min: " << minNode(root)->data << endl;
    cout << "Max: " << maxNode(root)->data << endl;
    cout << "Inorder Successor: " << inorderSuccessor(root, n)->data << endl;
    cout << "Inorder Predecessor: " << inorderPredecessor(root, n)->data << endl;
}
