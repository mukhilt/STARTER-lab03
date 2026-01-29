#include "intbst.h"
#include <iostream>

using namespace std;

int main() {
    IntBST tree;

    tree.insert(64);
    tree.insert(8);
    tree.insert(4);
    tree.insert(32);
    tree.insert(16);
    tree.insert(128);
    tree.insert(512);
    tree.insert(256);

    cout << "Pre-order: ";
    tree.printPreOrder();
    cout << endl;

    cout << "In-order: ";
    tree.printInOrder();
    cout << endl;

    cout << "Post-order: ";
    tree.printPostOrder();
    cout << endl;

    cout << "Sum: " << tree.sum() << endl;
    cout << "Count: " << tree.count() << endl;

    cout << "Contains 64? " << tree.contains(64) << endl;
    cout << "Contains 17? " << tree.contains(17) << endl;

    cout << "Predecessor of 64: " << tree.getPredecessor(64) << endl;
    cout << "Successor of 64: " << tree.getSuccessor(64) << endl;

    cout << "Removing 4" << endl;
    tree.remove(4);

    cout << "In-order after remove: ";
    tree.printInOrder();
    cout << endl;

    return 0;
}



