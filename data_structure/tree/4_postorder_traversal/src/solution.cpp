#include "solution.h"

using std::vector;

vector<int> Solution::post_order_traversal(Node* root) {
    vector<int> ret;
    vector<Node*> node_stack;
    Node* last_node;
    
    while(root != NULL || node_stack.size() != 0) {
        Node* current;
        if (root != NULL) {
            node_stack.push_back(root);
            root = root->left;
        } else {
            current = node_stack.back();
            if (current->right != NULL && last_node != current->right) {
                root = current->right;
            } else {
                ret.push_back(current->val);
                node_stack.pop_back();
                last_node = current;
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
