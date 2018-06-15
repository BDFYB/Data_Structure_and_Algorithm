#ifndef PREORDER_TRAVERSAL
#define PREORDER_TRAVERSAL
#include <vector>
#include "tree.h"

class Solution {
public:
    std::vector<int> postorder_traversal(Node*);
    void postorder_traversal_recursion(std::vector<int>&, Node*);
};



#endif
