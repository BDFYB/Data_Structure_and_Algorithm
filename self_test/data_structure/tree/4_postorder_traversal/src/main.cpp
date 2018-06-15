#include "tree.h"
#include "solution.h"

using std::vector;

void print_vector(vector<int> data) {
    for(int i = 0; i < data.size(); i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
};

int main(int argv, char* argc[]) {
    Tree tree(6);
    tree.insert(tree.root(), 8);
    tree.insert(tree.root(), 4);
    tree.insert(tree.root(), 2);
    tree.insert(tree.root(), 3);
    tree.insert(tree.root(), 7);
    tree.insert(tree.root(), 9);
    tree.insert(tree.root(), 5);
    tree.insert(tree.root(), 1);
    Solution solution;
    std::cout << "递归方式实现的中序遍历：";
    vector<int> result_1;
    solution.postorder_traversal_recursion(result_1, tree.root());
    print_vector(result_1);
    std::cout << "非递归方式实现的中序遍历：";
    vector<int> result_2 = solution.postorder_traversal(tree.root());
    print_vector(result_2);
    return 0;
}
