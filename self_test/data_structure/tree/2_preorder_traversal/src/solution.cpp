#include "tree.h"
#include "solution.h"

using std::vector;

vector<int> Solution::preorder_traversal(Node* node) {
    vector<int> ret;
    vector<Node*> node_stack;
    if (node == NULL) {
        return ret;
    }

    while (node != NULL || node_stack.size() > 0) {
        if (node != NULL) {
            node_stack.push_back(node);
            ret.push_back(node->val);
            node = node->left;
        } else {
            node = node_stack.back();
            node_stack.pop_back();
            node = node->right;
        }
    }


    return ret;
}

void Solution::preorder_traversal_recursion(vector<int>& ret, Node* node) {
    if (node == NULL) {
        return;
    }
    ret.push_back(node->val);
    preorder_traversal_recursion(ret, node->left);
    preorder_traversal_recursion(ret, node->right);
};
