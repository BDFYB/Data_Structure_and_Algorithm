#include "solution.h"
#include <queue>
#include <iostream>

using std::vector;
using std::queue;

/*
vector<int> Solution::level_order(Node* root) {
}
*/

vector<vector<int> > Solution::zigzag_level_order(Node* root) {
    vector<vector<int> > ret;
    if (root == NULL) {
        return ret;
    }
    vector<Node*> inorder_node_stack;
    vector<Node*> reverse_node_stack;
    bool flag = true;
    
    inorder_node_stack.push_back(root);
    while (true) {
        if (flag) {
            vector<int> current_level;
            while (inorder_node_stack.size() > 0) {
                Node* current = inorder_node_stack.back();
                inorder_node_stack.pop_back();
                if (current->left != NULL) {
                    reverse_node_stack.push_back(current->left);
                }
                if (current->right != NULL) {
                    reverse_node_stack.push_back(current->right);
                }
                current_level.push_back(current->val);
            }
            ret.push_back(current_level);
            flag = flag? false:true;
            if (reverse_node_stack.size() == 0) {
                break;
            }
        } else {
            vector<int> current_level;
            while (reverse_node_stack.size() > 0) {
                Node* current = reverse_node_stack.back();
                reverse_node_stack.pop_back();
                if (current->right != NULL) {
                    inorder_node_stack.push_back(current->right);
                }
                if (current->left != NULL) {
                    inorder_node_stack.push_back(current->left);
                }
                current_level.push_back(current->val);
            }
            flag = flag? false:true;
            ret.push_back(current_level);
            if (inorder_node_stack.size() == 0) {
                break;
            }
        }
    }
    return ret;
};

