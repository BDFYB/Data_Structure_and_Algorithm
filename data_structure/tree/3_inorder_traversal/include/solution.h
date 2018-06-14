#ifndef TREE_IN_ORDER_TRAVERSAL_SOLUTION_H
#define TREE_IN_ORDER_TRAVERSAL_SOLUTION_H
#include <vector>
#include "tree.h"

class Solution {
public:
    std::vector<int> in_order_traversal(Node* root);
    void in_order_traversal_recursion(std::vector<int>& ret, Node* root);
};

#endif
