#ifndef TREE_H
#define TREE_H
#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val), left(NULL), right(NULL) {};
};

class Tree {
public:
    explicit Tree(int val);
    ~Tree();
    void delete_node(Node*);
    void insert(Node* node, int val);
    Node* root();
    void mid_order_traversal(Node* node);

private:
    Node* _root;
};

#endif
