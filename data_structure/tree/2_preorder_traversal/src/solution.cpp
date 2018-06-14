#include "solution.h"

using std::vector;

vector<int> Solution::pre_order_traversal(Node* root) {
    vector<Node*> node_stack;
    vector<int> ret;
    while (node_stack.size() > 0 || root != NULL) {
        if (root != NULL) {
            node_stack.push_back(root);
            ret.push_back(root->val);
            root = root->left;
        } else {
            root = node_stack.back();
            node_stack.pop_back();
            root = root->right;
        }
    }

    return ret;
};

void Solution::pre_order_traversal_recursion(vector<int>& ret, Node* root) {
    if (root == NULL) {
        return;
    }
    ret.push_back(root->val);
    pre_order_traversal_recursion(ret, root->left);
    pre_order_traversal_recursion(ret, root->right);
    return;

};
