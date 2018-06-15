#include "solution.h"
#include <queue>

using std::vector;
using std::queue;

vector<int> Solution::level_order(Node* root) {
    vector<int> ret;
    std::cout << "递归这种方式不分层无法实现" << std::endl;
    return ret;
}

vector<vector<int> > Solution::level_order_ret_mat(Node* root) {
    vector<vector<int> > ret_root;
    vector<int> tmp;
    vector<vector<int> > ret_left;
    vector<vector<int> > ret_right;

    if (root != NULL) {
        tmp.push_back(root->val);
        ret_root.push_back(tmp);
    }

    if (root != NULL && root->left != NULL) {
        ret_left = level_order_ret_mat(root->left);
    }
    if (root != NULL && root->right != NULL) {
        ret_right = level_order_ret_mat(root->right);
    }

    for (int i = 0; i < ret_left.size() || i < ret_right.size(); i++) {
        if (i < ret_left.size() && i < ret_right.size()) {
            ret_left[i].insert(ret_left[i].end(), ret_right[i].begin(), ret_right[i].end());
            ret_root.push_back(ret_left[i]);
        } else if (i < ret_left.size()) {
            ret_root.push_back(ret_left[i]);
        } else {
            ret_root.push_back(ret_right[i]);
        }
    }
    return ret_root;
};


