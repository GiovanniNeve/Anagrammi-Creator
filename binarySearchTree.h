#include <iostream>
#include <cstring>

/* Binary Search Tree class */
class BST {
private:
    struct Node {   /* Node struct */
        std::string data;
        Node* right = nullptr;
        Node* left = nullptr;
    };

public:
    Node* root = new Node;

    /* Functions */
    struct Node* createNode(std::string);
    struct Node* insertData(std::string, Node*);
    void getData(Node*);
    void search(std::string, Node*);
};

/* Create new node */
BST::Node* BST::createNode(std::string value) {
    struct Node* newNode = new Node;
    newNode->data = value;

    return newNode;
}

/* Insert data in the BST with recursion */
BST::Node* BST::insertData(std::string value, Node* node) {
    if(!node) {
        node = createNode(value);
        return node;
    }

    if(value.compare(node->data) <= 0) {
        node->left = insertData(value, node->left);
    } else if(value.compare(node->data) > 0) {
        node->right = insertData(value, node->right);
    }

    return node;
}

/* Search a word in the BST with recursion */
void BST::search(std::string value, Node* node) {
    if(!node) {
        return;
    } else if(value.compare(node->data) < 0) {
        search(value, node->left);
    } else if(value.compare(node->data) > 0) {
        search(value, node->right);
    } else if(value == node->data) {
        std::cout << "\nWord searched: " << value << "\n" << "Word found: " << node->data  << "\n";
    }
}

/* Output all data with recursion */
void BST::getData(Node* node) {
    if(node) {
        getData(node->left);
        std::cout << node->data << "\n";
        getData(node->right);
    }
}
