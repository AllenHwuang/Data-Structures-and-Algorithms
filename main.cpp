#include <iostream>
#include "Data Structures/List/LinkList.cpp"
#include "Data Structures/List/SequenceList.cpp"


int main() {
    std::cout << "Hello, World!" << std::endl;
    auto *listLink = new LinkList();
    int m = listLink->run();
    return 0;
}
