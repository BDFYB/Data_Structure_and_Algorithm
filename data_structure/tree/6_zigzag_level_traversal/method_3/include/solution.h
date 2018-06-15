#ifndef TREE_LEVEL_TRAVERSAL_SOLUTION_H
#define TREE_LEVEL_TRAVERSAL_SOLUTION_H
#include <vector>
#include "tree.h"

class Solution {
public:
    std::vector<int> level_order(Node* root);
    std::vector<std::vector<int> > level_order_ret_mat(Node* root);
};

#endif
