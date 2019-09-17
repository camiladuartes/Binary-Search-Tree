#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>

template <typename T>
struct Node {
    T key;
    int height;
    bool isRoot = false;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
void binTreeSearch(Node<T> * &pt, int x, int f){
    if(pt != nullptr){
        if(pt->key == x){
            std::cout << "Key '" << x << "' was found!\n";
            f = 1; // chave encontrada em pt
        }
        else{
            if(pt->key > x){
                if(pt->left == nullptr){
                    std::cout << "Key '" << x << "' was not found!\n";
                    f = 2; // chave não encontrada e pt aponta pro nó à esquerda
                }
                else
                    pt = pt->left;
            }
            else{
                if(pt->right == nullptr){
                    std::cout << "Key '" << x << "' was not found!\n";
                    f = 3; // chave não encontrada e pt aponta pro nó à direita
                }
                else
                    pt = pt->right;
            }
            if(f < 1)
                binTreeSearch(pt, x, f);
        }
    }
    else{
        std::cout << "Key '" << x << "' was not found! Null pointer sent.\n";
    }
}

template <typename T>
void binTreeInsertion(Node<T> *&pt, int x, int f) {

    binTreeSearch(pt, x, f);
    if(f == 1)
        std::cout << "The key " << x << " already exists!\n";
    else{
        Node<T> *pt1 = new Node<T>;
        pt1->key = x;
        pt1->left = nullptr;
        pt1->right = nullptr;
        if(f == 0){
            pt = new Node<T>;
            pt->isRoot = true;
            pt = pt1;
        }
        else{
            if(f == 2)
                pt->left = pt1;
            else
                pt->right = pt1;
        }
        std::cout << "Adding...\nKey '" << x << "' was has been added to the tree.\n";
    }
}

void binTreeRemoval() {

}

#endif