#include "../include/binTree.h"

int main(){
    Node<int> *root{nullptr};
    binTreeSearch(root, 2, 0);
    std::cout << std::endl;

    binTreeInsertion(root, 20, 0);
    binTreeSearch(root, 20, 0);
    std::cout << std::endl;

    binTreeInsertion(root, 5, 0);
    binTreeSearch(root, 5, 0);
    return 0;
}