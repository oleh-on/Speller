
#include "AVL.h"

AVL::~AVL() {
    cleanTree(root);
}

void AVL::cleanTree(Node *node) {
    if(node == nullptr){
        return;
    }
    cleanTree(node->left);
    cleanTree(node->right);
    delete node;
}

void AVL::add(const std::string& value)
{
    root = add(root, value);
}

Node* AVL::add(Node* node, const std::string& value)
{
    if (node == nullptr) {
        node = new Node(value);
        return node;
    }
    else if (value < node->key) {
        node->left = add(root->left, value);
    }
    else if (value > node->key) {
        node->right = add(node->right, value);
    }
    return balance(node);
}

Node* AVL::rightRotate(Node *node)
{
    Node* newNode = node->left;
    node->left = newNode->right;
    newNode->right = node;
    fixHeight(node);
    fixHeight(newNode);
    return newNode;
}

Node* AVL::leftRotate(Node *node)
{
    Node* newNode = node->right;
    node->right = newNode->left;
    newNode->left = node;
    fixHeight(node);
    fixHeight(newNode);
    return newNode;
}

bool AVL::check(const std::string& value) {
    Node* tmp = check(root, value);
    if (tmp == nullptr) {
        return false;
    }
    return tmp->key == value;
}

Node* AVL::check(Node* node, const std::string& value) {
    if (node) {
        if (node->key == value) {
            return node;
        }
        else if (node->key > value) {
            check(node->left, value);
        }
        else if (node->key < value) {
            check(node->right, value);
        }
    } else {
        return 0;
    }
}

int AVL::getHeight(Node* node)
{
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

Node* AVL::balance(Node* node)
{
    fixHeight(node);
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->right) < 0)
            node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->left) > 0)
            node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    return node;
}

void AVL::fixHeight(Node* node)
{
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

int AVL::balanceFactor(Node* node)
{
    return getHeight(node->right) - getHeight(node->left);
}



