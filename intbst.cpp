// intbst.cpp
// Implements class IntBST
// Mukhil Thavathiru murugan, Jan 28

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n == nullptr) {
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
        return true;
    }
    return insert(value, root);

}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info) {
        return false;
    }
    if (value > n->info) {
        if (n->right == nullptr) {
            n->right = new Node(value);
            return true;
        }
        return insert(value, n->right);
    }
    if (value < n-> info) {
        if (n->left == nullptr) {
            n->left = new Node(value);
            return true;
        }
        return insert(value, n->left);
    }
    return false;
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n == nullptr) {
        return;
    }
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
   printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if (n == nullptr) {
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if (n == nullptr) {
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    int sumVal = 0;
    if (n == nullptr) {
        return 0;
    }
    sumVal += n->info;
    sumVal += sum(n -> left);
    sumVal += sum(n -> right);
    return sumVal;
}

// return count of values
int IntBST::count() const {
    return count(root);

}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (n == nullptr) {
        return 0;
    }
    int countVal = 0;
    if (n != nullptr) {
        countVal++;
    }
    countVal += count(n->left);
    countVal += count(n->right);
    return countVal;

}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (n == nullptr) {
        return nullptr;
    }
    if (value == n->info) {
        return n;
    }
    if (value > n->info) {
        return getNodeFor(value, n->right);
    }
    if (value < n->info) {
        return getNodeFor(value, n->left);
    }
    return nullptr;
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    Node *result = getNodeFor(value, root);
    if (result == nullptr) {
        return false;
    }
    else if (result != nullptr) {
        return true;
    }
    return false;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node *target = getNodeFor(value, root);
    if (target == nullptr) {
        return nullptr;
    }
    if (target -> left != nullptr) {
        Node* curr = target -> left;
        while (curr -> right != nullptr) {
            curr = curr -> right;
        }
        return curr;
    }
    Node* predecessor = nullptr;
    Node* curr = root;
    while (curr != nullptr) {
        if (value > curr -> info) {
            predecessor = curr;
            curr = curr -> right;
        }
        else if (value < curr -> info) {
            curr = curr -> left;
        }
        else {
            break;
        }
    }
    return predecessor;


}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node *targetNode = getPredecessorNode(value);
    if (targetNode == nullptr) {
        return 0;
    }
    else {
        return targetNode -> info;
    }
    return 0;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node *result = getNodeFor(value, root);
    if (result == nullptr) {
        return nullptr;
    }
    if (result -> right != nullptr) {
        Node* curr = result -> right;
        while (curr->left != nullptr) {
            curr = curr -> left;
        }
        return curr;
    }
    Node* successor = nullptr;
    Node* curr = root;
    while (curr != nullptr) {
        if (value < curr -> info) {
            successor = curr;
            curr = curr -> left;
        }
        else if (value > curr -> info) {
            curr = curr -> right;
        }
        else {
            break;
        }
    }
    return successor;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node *targetNode = getSuccessorNode(value);
    if (targetNode == nullptr) {
        return 0;
    }
    else {
        return targetNode -> info;
    }
    return 0;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    if (root == nullptr) {
        return false;
    }
    Node *target = getNodeFor(value, root);
    if (target == nullptr) {
        return false;
    }
    Node* parent = nullptr;
    Node* current = root;
    while (current != nullptr) {
        parent = current;
        if (current -> info > value) {
            current = current -> left;
        }
        else if (current -> info < value) {
            current = current -> right;
        }
    }
    if (target -> left != nullptr && target -> right != nullptr) {
        Node* succesorParent = target;
        Node* successor = target -> left;
        while (successor -> left != nullptr) {
            succesorParent = successor;
            successor = successor -> left;
        }
        target -> info = successor -> info;
        parent = succesorParent;
        target = successor;
    }
    Node* child = nullptr;
    if (target -> left != nullptr) {
        child = target -> left;
    }
    else {
        child = target -> right;
    }
    if (parent == nullptr) {
        root = child;
    }
    else if (parent -> right == target){
        parent -> right = child;
    }
    else {parent -> left = child;}
    {
        parent -> left = child;
    }
    delete target;
    return true;
}
