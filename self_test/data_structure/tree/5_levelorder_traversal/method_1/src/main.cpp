#include "solution.h"
#include "tree.h"

using std::vector;

void print_vector(vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
};

void print_matrix(vector<vector<int> > data) {
    for(int i = 0; i < data.size(); i++) {
        vector<int> level = data[i];
        for (int j = 0; j < level.size(); j++) {
            std::cout << level[j] << ' ';
        }
        std::cout << std::endl;
    }
}

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
    /*
    std::cout << "mid order: ";
    tree.midorder(tree.root());
    std::cout << std::endl;
    std::cout << "pre order: ";
    tree.preorder(tree.root());
    std::cout << std::endl;
    std::cout << "post order: ";
    tree.postorder(tree.root());
    std::cout << std::endl;
    */
    Solution solution;

    vector<vector<int> > result_2 = solution.levelorder_traversal(tree.root());
    print_matrix(result_2);
    return 0;
}

