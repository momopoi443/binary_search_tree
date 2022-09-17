
#include "BinarySearchTree.h"
#include <iostream>

Node::Node(const Data& val) {
    this->val = val;
    left = nullptr;
    right = nullptr;
}



void BinarySearchTree::inorderTraversal(Node* root, void (*func)(Node*)) {
    if (root != nullptr) {
        inorderTraversal(root->left, func);
        func(root);
        inorderTraversal(root->right, func);
    }
}

void BinarySearchTree::postorderTraversal(Node* root, void (*func)(Node*)) {
    if (root != nullptr) {
        postorderTraversal(root->left, func);
        postorderTraversal(root->right, func);
        func(root);
    }
}

bool BinarySearchTree::findInner(Node* root, const Data& val) {
    if (root == nullptr)
        return false;
    else if (val < root->val)
        return findInner(root->left, val);
    else if (val > root->val)
        return findInner(root->right, val);
    return true;
}

Node* BinarySearchTree::insertInner(Node* root, Data& val) {
    if (root == nullptr) {
        tSize++;
        return new Node(val);
    }
    else if (val < root->val)
        root->left = insertInner(root->left, val);
    else if (val > root->val)
        root->right = insertInner(root->right, val);
    return root;
}

Node* BinarySearchTree::eraseInner(Node* root, const Data& val) {
    if (root == nullptr)
        return root;

    if (val < root->val)
        root->left = eraseInner(root->left, val);
    else if (val > root->val)
        root->right = eraseInner(root->right, val);
    else if (root->left == nullptr && root->right == nullptr) {
        tSize--;
        root = nullptr;
    }
    else if (root->left == nullptr) {
        tSize--;
        root = root->right;
    }
    else if (root->right == nullptr) {
        tSize--;
        root = root->left;
    }
    else {
        root->val = min(root->right)->val;
        root->right = eraseInner(root->right, root->val);
    }
    return root;
}

size_t BinarySearchTree::heightInner(Node* root) {
    if (root == nullptr)
        return 0;
    return std::max(heightInner(root->left), heightInner(root->right)) + 1;
}

Node *BinarySearchTree::min(Node *root) {
    if (root->left == nullptr)
        return root;
    return min(root->left);
}

void BinarySearchTree::findInRangeInner(Node *root, const Data &min, const Data &max, std::vector<Data>& to) {
    if (root == nullptr)
        return;
    if (root->val < min)
        findInRangeInner(root->right, min, max, to);
    else if (root->val > max)
        findInRangeInner(root->left, min, max, to);
    else {
        to.push_back(root->val);
        findInRangeInner(root->right, min, max, to);
        findInRangeInner(root->left, min, max, to);
    }
}



Data BinarySearchTree::min() const {
    if (root == nullptr) throw "BTS empty";
    Node* buff = root;
    while (buff->left != nullptr) buff = buff->left;
    return buff->val;
}

Data BinarySearchTree::max() const {
    if (root == nullptr) throw "BTS empty";
    Node* buff = root;
    while (buff->right != nullptr) buff = buff->right;
    return buff->val;
}

bool BinarySearchTree::find(const Data &val) {
    return findInner(root, val);
}

void BinarySearchTree::insert(Data &val) {
    if (root == nullptr)
        root = insertInner(root, val);
    else
        insertInner(root, val);
}

void BinarySearchTree::erase(const Data &val) {
    if (root == nullptr) throw "BTS empty";
    eraseInner(root, val);
}

size_t BinarySearchTree::height() {
    return heightInner(root);
}

size_t BinarySearchTree::size() const { return tSize;}

void BinarySearchTree::print() {
    std::cout << "All elements in sorted order:" << std::endl;
    inorderTraversal(root, [] (Node* pointer) {std::cout << pointer->val << std::endl;});
}

std::vector<Data> BinarySearchTree::findInRange(const Data &min, const Data &max) {
    if (max <  min) throw "Incorrect borders";

    std::vector<Data> toReturn(0);
    findInRangeInner(root, min, max, toReturn);
    return toReturn;
}

void BinarySearchTree::clear() {
    postorderTraversal(root, [] (Node* pointer) {delete pointer;});
    root = nullptr;
}

BinarySearchTree::BinarySearchTree(): root(nullptr), tSize(0) {}

BinarySearchTree::~BinarySearchTree() {
    clear();
}