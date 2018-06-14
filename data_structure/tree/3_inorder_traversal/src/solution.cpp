#include "solution.h"

using std::vector;
vector<int> Solution::in_order_traversal(Node* root) {
    vector<Node*> node_stack;
    vector<int> ret;
    while (node_stack.size() > 0 || root != NULL) {
        if (root != NULL) {
            node_stack.push_back(root);
            root = root->left;
        } else {
            if (node_stack.size() > 0) {
                root = node_stack.back();
                ret.push_back(root->val);
                node_stack.pop_back();
                root = root->right;
            }
        }
    }
    return ret;
};

void Solution::in_order_traversal_recursion(vector<int>& ret, Node* root) {
    if (root == NULL) {
        return;
    }
    in_order_traversal_recursion(ret, root->left);
    ret.push_back(root->val);
    in_order_traversal_recursion(ret, root->right);
    return;

};
