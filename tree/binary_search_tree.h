#pragma once

#include <iostream>

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {

public:
    BinarySearchTree();
    BinarySearchTree(int data);

    Node* find(int data);
    void insert(int data);
    bool delete_data(int data);

private:
    Node* root = nullptr;
};