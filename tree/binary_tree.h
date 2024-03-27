#pragma once

#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BinaryTree {

public:
    void preOrder(Node *node);
    void inOrder(Node *node);
    void postOrder(Node *node);

private:
    Node *root = nullptr;
};