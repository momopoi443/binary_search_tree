
#ifndef INC_2_4_0_BINARYSEARCHTREE_H
#define INC_2_4_0_BINARYSEARCHTREE_H

#include "../Data/Data.h"
#include <vector>

struct Node {
    Data val;
    Node* left;
    Node* right;

    explicit Node(const Data& val);

    ~Node() = default;
};

struct BinarySearchTree{
private:
    Node* root;
    size_t tSize;

    void inorderTraversal(Node* root, void (*func)(Node*));

    void postorderTraversal(Node* root, void (*func)(Node*));

    bool findInner(Node* root, const Data& val);

    Node* insertInner(Node* root, Data& val);

    Node* eraseInner(Node* root, const Data& val);

    size_t heightInner(Node* root);

    Node* min(Node* root);

    Node* max(Node* root);

    void findInRangeInner(Node* root, const Data& min, const Data& max, std::vector<Data>& to);

public:
    Data min() const;

    Data max() const;

    bool find(const Data& val);

    void erase(const Data& val);

    void insert(Data& val);

    size_t height();

    size_t size() const;

    void print();

    std::vector<Data> findInRange(const Data& min, const Data& max);

    void clear();

    BinarySearchTree();

    ~BinarySearchTree();
};

#endif
