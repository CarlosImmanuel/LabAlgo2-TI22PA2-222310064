#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *createNode(int data) {
  Node *newNode = new Node();
  if (!newNode) {
    cout << "Gagal membuat node baru." << endl;
    return NULL;
  }
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *insertNode(Node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
    return root;
  }
  if (data < root->data)
    root->left = insertNode(root->left, data);
  else if (data >= root->data)
    root->right = insertNode(root->right, data);
  return root;
}

void preOrderTraversal(Node *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

int main() {
  Node *root = NULL;
  root = insertNode(root, 12);
  root = insertNode(root, 16);
  root = insertNode(root, 20);
  root = insertNode(root, 24);
  root = insertNode(root, 32);
  cout << "Hasil pre-order traversal: ";
  preOrderTraversal(root);
  return 0;
}