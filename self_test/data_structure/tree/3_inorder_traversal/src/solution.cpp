#include "tree.h"
#include "solution.h"

using std::vector;

vector<int> Solution::inorder_traversal(Node* node) {
    vector<int> ret;
    vector<Node*> node_stack;
    if (node == NULL) {
        return ret;
    }
    while (node_stack.size() > 0 || node != NULL) {
        if (node != NULL) {
            node_stack.push_back(node);
            node = node->left;
        } else {
            node = node_stack.back();
            node_stack.pop_back();
            ret.push_back(node->val);
            node = node->right;
        }
    }
    return ret;
}

void Solution::inorder_traversal_recursion(vector<int>& ret, Node* node) {
    if (node == NULL) {
        return;
    }
    inorder_traversal_recursion(ret, node->left);
    ret.push_back(node->val);
    inorder_traversal_recursion(ret, node->right);
};
