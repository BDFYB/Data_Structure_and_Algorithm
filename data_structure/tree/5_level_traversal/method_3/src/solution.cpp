#include "solution.h"
#include <queue>

using std::vector;
using std::queue;

vector<int> Solution::level_order(Node* root) {
    vector<int> ret;
    std::cout << "游标这种方式不分层同方案一" << std::endl;
    return ret;
}

vector<vector<int> > Solution::level_order_ret_mat(Node* root) {
    vector<vector<int> > ret;

    if (root == NULL) {
        return ret;
    }
    queue<Node*> node_queue;
    node_queue.push(root);
    //放置一个空的占位
    ret.push_back(vector<int>());

    int level = 0;
    Node* flag = root;

    while (node_queue.size() > 0) {
        Node* current = node_queue.front();
        node_queue.pop();
        ret[level].push_back(current->val);
        if (current->left != NULL) {
            node_queue.push(current->left);
        }
        if (current->right != NULL) {
            node_queue.push(current->right);
        }
        if (current == flag) {
            flag = node_queue.back();
            ret.push_back(vector<int>());
            level += 1;
        }
        
    }
    ret.pop_back();

    return ret;
};









