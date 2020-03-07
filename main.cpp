#include <iostream>
#include "Data Structures/List/LinkList.cpp"
#include "Data Structures/List/SequenceList.cpp"


int main() {
    std::cout << "Hello, World!" << std::endl;
    auto *listLink = new LinkList();
    auto *sequenceList = new SequenceList();
    int m = listLink->run();
    int n = sequenceList->run();
    return 0;
}
