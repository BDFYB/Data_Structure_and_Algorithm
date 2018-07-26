#include "tree.h"
#include <iostream>
#include <queue>

using std::vector;
using std::queue;

Tree::Tree() {
    root = NULL;
};

Tree::Tree(int val) {
    root = new Node(val);
};

Node* Tree::insert(Node* roots, int val) {
    if (roots == NULL) {
        roots = new Node(val);
        return roots;
    } 
    if (roots->val > val) {
        if (roots->left != NULL) {
            return insert(roots->left, val);
        } else {
            roots->left = new Node(val);
            return roots->left;
        }
    } else {
        if (roots->right != NULL) {
            return insert(roots->right , val);
        } else {
            roots->right = new Node(val);
            return roots->right;
        }
    }
};

Node* Tree::get_root() {
    return root;
}

void Tree::preorder(vector<int>& result, Node* p_node) {
    vector<Node*> node_stack;
    while (node_stack.size() > 0 || p_node != NULL) {
        if (p_node != NULL) {
            result.push_back(p_node->val);
            node_stack.push_back(p_node);
            p_node = p_node->left;
        } else {
            p_node = node_stack.back()->right;
            node_stack.pop_back();
        }
    }

};

void Tree::preorder_recursion(vector<int>& result, Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    result.push_back(p_node->val);
    preorder(result, p_node->left);
    preorder(result, p_node->right);
};

void Tree::inorder(vector<int>& result, Node* p_node) {
    vector<Node*> node_stack;
    while (node_stack.size() != 0 || p_node != NULL) {
        if (p_node != NULL) {
            node_stack.push_back(p_node);
            p_node = p_node->left;
        } else {
            Node* current = node_stack.back();
            node_stack.pop_back();
            result.push_back(current->val);
            p_node = current->right;
        }
    } 
};

void Tree::inorder_recursion(vector<int>& result, Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    inorder_recursion(result, p_node->left);
    result.push_back(p_node->val);
    inorder_recursion(result, p_node->right);
};

void Tree::postorder(vector<int>& result, Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    vector<Node*> node_stack;
    Node* last_node;
    while (node_stack.size() != 0 || p_node != NULL) {
        Node* current;
        if (p_node != NULL) {
            node_stack.push_back(p_node);
            p_node = p_node->left;
        } else {
            current = node_stack.back();
            if (current->right == NULL || last_node == current->right) {
                result.push_back(current->val);
                node_stack.pop_back();
                last_node = current;
            } else {
                p_node = current->right;
            }
        }
    }

};

void Tree::postorder_recursion(vector<int>& result, Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    postorder_recursion(result, p_node->left);
    postorder_recursion(result, p_node->right);
    result.push_back(p_node->val);
};

void Tree::level_traversal(vector<int>& result, Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    queue<Node*> node_queue;
    node_queue.push(p_node);
    while (node_queue.size() != 0) {
        Node* current = node_queue.front();
        node_queue.pop();
        result.push_back(current->val);
        if (current->left != NULL) {
            node_queue.push(current->left);
        }
        if (current->right != NULL) {
            node_queue.push(current->right);
        }
    }
};

void Tree::zigzag_level_traversal(vector<int>& result, Node* p_node) {
    if (p_node == NULL) {
        return;
    }
    vector<Node*> node_stack;
    vector<Node*> node_stack_reverse;
    node_stack.push_back(p_node);

    while (node_stack.size() != 0 || node_stack_reverse.size() != 0) {
        Node* current;
        if (node_stack.size() != 0) {
            while (node_stack.size() != 0) {
                current = node_stack.back();
                node_stack.pop_back();
                if (current != NULL) {
                    result.push_back(current->val);
                    node_stack_reverse.push_back(current->left);
                    node_stack_reverse.push_back(current->right);                    
                }
            }
        } else {
            while (node_stack_reverse.size() != 0) {
                current = node_stack_reverse.back();
                node_stack_reverse.pop_back();
                if (current != NULL) {
                    result.push_back(current->val);
                    node_stack.push_back(current->right);
                    node_stack.push_back(current->left);     
                }           
            }
        }
    }
};


void Tree::delete_node(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL) {
        delete_node(node->left);
    }
    if (node->right!= NULL) {
        delete_node(node->right);
    }
    delete node;
};

Tree::~Tree() {
    delete_node(root);
};
