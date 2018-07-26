#include "tree.h"
#include <iostream>
#include <vector>

using std::vector;
void print_vector(vector<int>& data) {
    for (vector<int>::iterator it = data.begin(); it != data.end(); it++) {
        std::cout << *it << " ";
    };
    std::cout << std::endl;
};

int main(int argc, char* argv[]) {
    Tree tree(6);
    tree.insert(tree.get_root(), 4);
    tree.insert(tree.get_root(), 8);
    tree.insert(tree.get_root(), 2);
    tree.insert(tree.get_root(), 5);
    tree.insert(tree.get_root(), 7);
    tree.insert(tree.get_root(), 9);
    tree.insert(tree.get_root(), 1);
    tree.insert(tree.get_root(), 3);
    vector<int> ret;
    tree.zigzag_level_traversal(ret, tree.get_root());
    print_vector(ret);
};
