#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() {

}

BinarySearchTree::BinarySearchTree(int data) {
    root = new Node(data);
}

Node* BinarySearchTree::find(int data) {
    Node *cur = root;
    while (cur != nullptr) {
        if (cur->data == data) {
            return cur;
        } else if (cur->data < data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return nullptr;
}

void BinarySearchTree::insert(int data) {
    if (root = nullptr) {
        root = new Node(data);
        return;
    }
    Node *cur = root;
    while (cur != nullptr) {
        if (data > cur->data) {
            if (cur->right == nullptr) {
                cur->right = new Node(data);
                return;
            }
            cur = cur->right;
        } else {
            if (cur->left == nullptr) {
                cur->left = new Node(data);
                return;
            }
            cur = cur->left;
        }
    }
}

bool BinarySearchTree::delete_data(int data) {
    if (root == nullptr) {
      std::cout << "root is null" << std::endl;
      return true;
    }

    Node *parent = nullptr;
    Node *cur = root;

    while (cur != nullptr && cur->data != data) {
        if (cur->data < data) {
            parent = cur;
            cur = cur->right;
        } else if (cur->data > data) {
            parent = cur;
            cur = cur->left;
        }
    }
    if (cur == nullptr) {
        std::cout << "this data not found!" << std::endl;
        return true;
    }

    // data == cur->data
    if (cur->left != nullptr && cur->right != nullptr) {
        Node *old_cur = cur;
        Node *new_parent = cur;
        cur = cur->right;
        while (cur->left != nullptr) {
            new_parent = cur;
            cur = cur->left;
        }
        old_cur->data = cur->data;
    }

    if (cur->left == nullptr && cur->right == nullptr) {
        if (parent->left == cur) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete cur;
    } else if (cur->left == nullptr || cur->right == nullptr) {
        if (parent->left == cur) {
            if (cur->left != nullptr) {
                parent->left = cur->left;
            } else {
                parent->left = cur->right;
            }
        } else if (parent->right == cur) {
            if (cur->left != nullptr) {
                parent->right = cur->left;
            } else {
                parent->right = cur->right;
            }
        }
        delete cur;
    } else {
        Node *old_cur = cur;
        Node *new_parent = cur;
        cur = cur->right;
        while (cur->left != nullptr) {
            new_parent = cur;
            cur = cur->left;
        }
        old_cur->data = cur->data;
        if (cur->right == nullptr) {
            delete cur;
        } else {
            if (new_parent->left == cur) {
                new_parent->left = cur->right;
            } else (new_parent->right == cur) {
                new_parent->right = cur->right;
            }
            delete cur;
        }
    }
}
    

    return true;
}

