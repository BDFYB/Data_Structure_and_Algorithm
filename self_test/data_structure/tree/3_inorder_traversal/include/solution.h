#ifndef PREORDER_TRAVERSAL
#define PREORDER_TRAVERSAL
#include <vector>
#include "tree.h"

class Solution {
public:
    std::vector<int> inorder_traversal(Node*);
    void inorder_traversal_recursion(std::vector<int>&, Node*);
};



#endif
