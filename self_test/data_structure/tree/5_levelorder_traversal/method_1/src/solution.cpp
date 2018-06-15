#include "tree.h"
#include "solution.h"
#include <queue>

using std::vector;
using std::queue;

vector<vector<int> > Solution::levelorder_traversal(Node* node) {
    vector<vector<int> > ret;
    vector<int> level_vector;
    vector<Node*> node_stack;
    queue<Node*> node_queue;

    if (node == NULL) {
        return ret;
    }
    node_queue.push(node);

    while (node_queue.size() > 0) {
        Node* current = node_queue.front();
        node_queue.pop();
        node_stack.push_back(current);
        if (current == NULL) {
            continue;
        }
        node_queue.push(current->left);
        node_queue.push(current->right);
    }
    level_vector.push_back(node->val);
    ret.push_back(level_vector);

    int level = 0;
    int i = 1;
    int j = 0;
    int step = 2;
    for (; i < node_stack.size(); i = j) {
        int cnt = 0;
        level_vector.clear();
        for (j = i; j < i + step; j++) {
            if (node_stack[j] != NULL) {
                level_vector.push_back(node_stack[j]->val);
                cnt += 2;
            }
        }
        step = cnt;
        if (level_vector.size() > 0) {
            ret.push_back(level_vector);
        }
    }
    return ret;
};
