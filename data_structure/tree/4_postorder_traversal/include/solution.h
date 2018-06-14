#ifndef TREE_PRE_TRAVERSAL_SOLUTION_H
#define TREE_PRE_TRAVERSAL_SOLUTION_H
#include <vector>
#include "tree.h"

class Solution {
public:
    std::vector<int> post_order_traversal(Node* root);
    void post_order_traversal_recursion(std::vector<int>& result, Node* root);
};

#endif
