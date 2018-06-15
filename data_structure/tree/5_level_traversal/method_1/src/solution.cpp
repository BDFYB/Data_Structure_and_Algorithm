#include "solution.h"
#include <queue>

using std::vector;
using std::queue;

vector<int> Solution::level_order(Node* root) {
    vector<int> ret;
    queue<Node*> upper_level_nodes;
    vector<Node*> ordered_nodes;

    if (root == NULL) {
        return ret;
    }
    upper_level_nodes.push(root);
    while (upper_level_nodes.size() > 0) {
        Node* tmp = upper_level_nodes.front();
        upper_level_nodes.pop();
        if (tmp == NULL) {
            continue;
        } 
        ordered_nodes.push_back(tmp);
        upper_level_nodes.push(tmp->left);
        upper_level_nodes.push(tmp->right);
    }

    for (int i = 0; i < ordered_nodes.size(); i++) {
        ret.push_back(ordered_nodes[i]->val);
    }
    return ret;
}

vector<vector<int> > Solution::level_order_ret_mat(Node* root) {
    vector<vector<int> > ret;
    queue<Node*> last_level_node;
    vector<Node*> ordered_nodes;
    vector<int> level_vector;

    if (root == NULL) {
        return ret;
    }
    last_level_node.push(root);
    while (last_level_node.size() > 0) {
        Node* tmp = last_level_node.front();
        last_level_node.pop();
        //把NULL也放进去，以便于按照数量分层
        ordered_nodes.push_back(tmp);
        if (tmp == NULL) {
            continue;
        }
        last_level_node.push(tmp->left);
        last_level_node.push(tmp->right);
    }

    //处理根节点
    level_vector.push_back(root->val);
    ret.push_back(level_vector);

    int i = 1;
    int j = 0;
    int step = 2;
    for (;i < ordered_nodes.size(); i = j) {
        level_vector.clear();
        int count = 0;
        for (j = i; j < i + step; j++) {
            if (ordered_nodes[j] != NULL) {
                level_vector.push_back(ordered_nodes[j]->val);
                count += 2;
            }
        }
        step = count;
        if (level_vector.size() > 0) {
            ret.push_back(level_vector);
        }
    }
    return ret;
};






