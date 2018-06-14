#include "solution.h"

using std::vector;

vector<int> Solution::post_order_traversal(Node* root) {
    vector<Node*> node_stack;
    vector<int> ret;
    Node* last_visit_node = NULL;
    while (node_stack.size() > 0 || root != NULL) {
        if (root != NULL) {
            node_stack.push_back(root);
            root = root->left;
        } else {
            Node* current = node_stack.back();
            if (current->right != NULL && last_visit_node != current->right) {
                root = current->right;
            } else {
                node_stack.pop_back();
                ret.push_back(current->val);
                last_visit_node = current;
            }
        }
    }
    return ret;
};

void Solution::post_order_traversal_recursion(vector<int>& result, Node* root) {
    if (root == NULL) {
        return;
    }
    post_order_traversal_recursion(result, root->left);
    post_order_traversal_recursion(result, root->right);
    result.push_back(root->val);
};
