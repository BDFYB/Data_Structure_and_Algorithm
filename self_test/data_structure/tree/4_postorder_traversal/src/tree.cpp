#include "tree.h"

Tree::Tree(int val) {
    _root = new Node(val);
};

Tree::~Tree() {
    if (_root != NULL) {
        delete_node(_root);
    }
};

void Tree::delete_node(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL) {
        delete_node(node->left);
    }
    if (node->right != NULL) {
        delete_node(node->right);
    }
    //std::cout << "free node: " << node->val << std::endl;
    delete node;
};

void Tree::insert(Node* roots, int val) {
    if (roots == NULL) {
        roots = new Node(val);
        return;
    }
    if (roots->val > val) {
        if (roots->left == NULL) {
            roots->left = new Node(val);
        } else {
            insert(roots->left, val);
        }
    } else {
        if (roots->right == NULL) {
            roots->right = new Node(val);
        } else {
            insert(roots->right, val);
        }
    }
}

void Tree::mid_order_traversal(Node* node) {
    if (node == NULL) {
        return;
    }
    mid_order_traversal(node->left);
    std::cout << node->val << ' ';
    mid_order_traversal(node->right);

};

Node* Tree::root() {
    return _root;
};

