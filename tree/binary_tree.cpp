#include "binary_tree.h"

void BinaryTree::preOrder(Node *node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void BinaryTree::inOrder(Node *node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

void BinaryTree::postOrder(Node *node) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}