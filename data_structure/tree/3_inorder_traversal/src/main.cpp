#include "solution.h"
#include "tree.h"

using std::vector;

void print_vector(vector<int> data) {
    for(int i = 0; i < data.size(); i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
};

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
    std::cout << "递归方式实现的中序遍历：";
    vector<int> result_1;
    solution.in_order_traversal_recursion(result_1, tree.roots());
    print_vector(result_1);
    std::cout << "非递归方式实现的中序遍历：";
    vector<int> result_2 = solution.in_order_traversal(tree.roots());
    print_vector(result_2);
    return 0;
}
