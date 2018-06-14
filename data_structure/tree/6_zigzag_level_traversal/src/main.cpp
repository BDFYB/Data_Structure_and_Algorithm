#include "solution.h"
#include "tree.h"

using std::vector;
int main(int argv, char* argc[]) {
    Tree tree(6);                
    tree.insert(tree.roots(), 8);
    tree.insert(tree.roots(), 4);
    tree.insert(tree.roots(), 2);
    tree.insert(tree.roots(), 3);
    tree.insert(tree.roots(), 7);
    tree.insert(tree.roots(), 9);
    tree.insert(tree.roots(), 5);
    tree.insert(tree.roots(), 1);
    /*
    std::cout << "mid order: ";
    tree.midorder(tree.roots());
    std::cout << std::endl;
    std::cout << "pre order: ";
    tree.preorder(tree.roots());
    std::cout << std::endl;
    std::cout << "post order: ";
    tree.postorder(tree.roots());
    std::cout << std::endl;
    */
    Solution solution;
    vector<vector<int> > result = solution.level_order(tree.roots());
    return 0;
}
