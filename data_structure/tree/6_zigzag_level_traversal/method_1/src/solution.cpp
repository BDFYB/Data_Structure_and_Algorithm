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

    queue<Node*> node_queue;

    ret.push_back(vector<int>());
    Node* flag = root;
    node_queue.push(root);

    int level = 0;
    while(node_queue.size() > 0) {
        Node* current = node_queue.front();
        node_queue.pop();
        /*
        if (level / 2 != 0) {
            ret[level].push_back(current->val);
        } else {
            ret[level].insert(ret[level].begin(), current->val);
        }
        */
        ret[level].insert(level%2 ? ret[level].begin() : ret[level].end(), current->val);

        if (current->left != NULL) {
            node_queue.push(current->left);
        }
        if (current->right != NULL) {
            node_queue.push(current->right);
        }
        if (flag == current) {
            level++;
            flag = node_queue.back();
            ret.push_back(vector<int>());
        }
    }
    ret.pop_back();

    return ret;
};

/*
vector<vector<int> > Solution::zigzag_level_order(Node* root) {
    vector<vector<int> > vv;
    if(root == NULL) return vv;

    int level = 0;
    Node *last = root;
    queue<Node*> q;

    q.push(root);
    vv.push_back(vector<int>());
    while(!q.empty()) {
        Node *p = q.front();
        q.pop();

        vv[level].insert(level%2 ? vv[level].begin() : vv[level].end(), p->val);
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);

        if(p == last) {
            level++;
            last = q.back();
            vv.push_back(vector<int>());
        }
    }
    vv.pop_back();

    return vv;
}
*/



