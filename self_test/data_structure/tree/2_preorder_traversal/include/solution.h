#ifndef PREORDER_TRAVERSAL
#define PREORDER_TRAVERSAL
#include <vector>
#include "tree.h"

class Solution {
public:
    std::vector<int> preorder_traversal(Node*);
    void preorder_traversal_recursion(std::vector<int>&, Node*);
};



#endif
