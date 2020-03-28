#include <iostream>
#include "Data Structures/List/LinkList.cpp"
#include "Data Structures/List/SequenceList.cpp"
#include "Data Structures/Tree/BinaryTree.cpp"


int main() {
    std::cout << "Hello, World!" << std::endl;
//    auto *listLink = new LinkList();
//    listLink->run();
    auto *btree = new BinaryTree();
    btree->run();
    return 0;
}
