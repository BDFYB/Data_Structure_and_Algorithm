#include "tree.h"

Tree::Tree() {root = NULL;};
Tree::Tree(int val) {root = new Node(val);};
Tree::~Tree() {
    delete_node(root);
};
Node* Tree::roots() {
    return root;
};

Node* Tree::search(Node* current_node, int val) {
    if (current_node->val == val) {
        return current_node;
    } else if (current_node->val < val) {
        if (current_node->right == NULL) {
            return NULL;
        }
        return search(current_node->right, val);
    } else if (current_node->val > val) {
        if (current_node->left == NULL) {
            return NULL;
        }
        return search(current_node->left, val);
    }
};

void Tree::insert(Node* roots, int val) {
    if (roots == NULL) {
        std::cout << "new node: " << val << std::endl;
        roots = new Node(val);
        return;
    }
    if (val < roots->val) {
        std::cout << "insert left" << std::endl;
        if (roots->left == NULL) {
            roots->left = new Node(val);
        } else {
            insert(roots->left, val);
        }
    } else {
        std::cout << "insert right" << std::endl;
        if (roots->right == NULL) {
            roots->right = new Node(val);
        } else {
            insert(roots->right, val);
        }
    }
};

void Tree::preorder(Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    std::cout << p_node->val << ' ';
    preorder(p_node->left);
    preorder(p_node->right);
};

void Tree::midorder(Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    midorder(p_node->left);
    std::cout << p_node->val << ' ';
    midorder(p_node->right);
};

void Tree::postorder(Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    postorder(p_node->left);
    postorder(p_node->right);
    std::cout << p_node->val << ' ';
};

void Tree::delete_node(Node *p_node) {
    if (p_node == NULL) {
        return;
    }
    if (p_node->left != NULL) {
        delete_node(p_node->left);
    }
    if (p_node->right != NULL) {
        delete_node(p_node->right);
    }
    delete p_node;
};

