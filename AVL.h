//
// Created by olehon on 3/4/20.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H

#include "Checker.h"

struct Node
{
    std::string key;
    Node* left;
    Node* right;
    int height;
    Node() = default;
    explicit Node(const std::string& value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

class AVL : public Checker {
public:
    explicit AVL(const std::string& name) : Checker(name), root(nullptr) {}
    ~AVL() override;
    void add(const std::string& value) override ;
    bool check(const std::string& value) override ;
private:
    Node* root;
    Node* add(Node* node, const std::string& value);
    int getHeight(Node* node);
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
    Node* check(Node* root, const std::string& value);
    Node* balance(Node* node);
    void fixHeight(Node* node);
    int balanceFactor(Node* p);
    void cleanTree(Node* node);
};

#endif //AVL_AVL_H
