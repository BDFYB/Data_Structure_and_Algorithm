#ifndef DATASTRUCTURE_TREE_H
#define DATASTRUCTURE_TREE_H

#include <iostream>
#include <vector>

#define DISSALOW_COPY_AND_ASSIGN(class_name) \
    class_name(const class_name&);\
    class_name& operator=(const class_name&)

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val), left(NULL), right(NULL) {};
};

class Tree{
public:
    Tree();
    explicit Tree(int val);

    Node* roots();

    //插入
    void insert(Node* roots, int val);

    //查找
    Node* search(Node* current_node, int val);

    //遍历
    void preorder(Node* p_node);
    void midorder(Node* p_node);
    void postorder(Node* p_node);

    void delete_node(Node *p_node);
    ~Tree();

private:
    Node* root;
    DISSALOW_COPY_AND_ASSIGN(Tree);
};

#endif
