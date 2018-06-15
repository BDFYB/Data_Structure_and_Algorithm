#include "tree.h"
#include "solution.h"

using std::vector;

vector<int> Solution::postorder_traversal(Node* node) {
    vector<int> ret;
    vector<Node*> node_stack;
    Node* flag = node;
    while (node_stack.size() > 0 || node != NULL) {
        if (node != NULL) {
            node_stack.push_back(node);
            node = node->left;
        } else {
            Node* current = node_stack.back();
            if (current -> right != NULL && current->right != flag) {
                node = current->right;
            } else {
                ret.push_back(current->val);
                node_stack.pop_back();
                flag = current;
            }
        }
    }
    return ret;
}

void Solution::postorder_traversal_recursion(vector<int>& ret, Node* node) {
    if (node == NULL) {
        return;
    }
    postorder_traversal_recursion(ret, node->left);
    postorder_traversal_recursion(ret, node->right);
    ret.push_back(node->val);
};
