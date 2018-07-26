#ifndef TREE_H
#define TREE_H

#define DISSALOW_COPY_AND_ASSIGN(class_name) \
    class_name(const class_name&);\
    class_name& operator=(const class_name&)

#include <vector>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val), left(NULL), right(NULL) {};
};

class Tree {
public:
    Tree();
    explicit Tree(int val);

    Node* insert(Node* roots, int val);
    void delete_node(Node* node);
    Node* get_root();
    void preorder(std::vector<int>& result, Node* p_node);
    void preorder_recursion(std::vector<int>& result, Node* p_node);
    void inorder(std::vector<int>& result, Node* p_node);
    void inorder_recursion(std::vector<int>& result, Node* p_node);
    void postorder(std::vector<int>& result, Node* p_node);
    void postorder_recursion(std::vector<int>& result, Node* p_node);

    void level_traversal(std::vector<int>& result, Node* p_node);
    void zigzag_level_traversal(std::vector<int>& result, Node* p_node);

    ~Tree();
private:
    Node* root;
    DISSALOW_COPY_AND_ASSIGN(Tree);
};

#endif
