#ifndef TREE_PRE_ORDER_TRAVERSAL_SOLUTION_H
#define TREE_PRE_ORDER_TRAVERSAL_SOLUTION_H
#include <vector>
#include "tree.h"

class Solution {
public:
    std::vector<int> pre_order_traversal(Node* root);
    void pre_order_traversal_recursion(std::vector<int>& ret, Node* root);
};

#endif
