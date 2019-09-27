#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <ostream>

template <typename T>
struct Node {
    T key;
    int height;
    bool isRoot = false;
    Node<T> *left;
    Node<T> *right;
    Node<T> *dad;
};

template <typename T>
void binTreeSearch(Node<T> *&pt, int x, int & f){
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

//template<typename T>
//void updateHeight(Node<T> tree);

template <typename T>
void binTreeInsertion(Node<T> *& pt, int x, int f) {

	Node<T>* root = pt;
    binTreeSearch(pt, x, f);
    if(f == 1)
        std::cout << "The key " << x << " already exists!\n";
    else{
        Node<T>* pt1 = new Node<T>;
        pt1->key = x;
        pt1->left = nullptr;
        pt1->right = nullptr;
        if(f == 0){
            pt = new Node<T>;
            pt->isRoot = true;
            pt = pt1;
        }
        else{
            if( f == 2 )
                pt->left = pt1;
            else
                pt->right = pt1;
        }
        std::cout << "Adding...\nKey '" << x << "' was has been added to the tree.\n";
		//updateHeight(root)
    }
}

void binTreeRemoval(Node<T> *&pt, int x, int f){
    binTreeSearch(pt, x, f);
    if(f == 1){
        if(pt->left == nullptr and pt->right == nullptr){ // é folha
            pt->dad = nullptr;
            delete pt;
        }
        else if(pt->left != nullptr and pt-> right == nullptr){ // tem uma subárvore vazia (1 filho)
            pt->dad->left = pt->left;
            delete pt;
        }
        else if(pt->left == nullptr and pt-> right != nullptr){ // tem uma subárvore vazia (1 filho)
            pt->dad->right = pt->right;
            delete pt;
        }
        else if(pt->left != nullptr and pt->right != nullptr){ // não é folha e tem dois filhos
            Node<T> *predecessor = pt->left;
            while(predecessor->right != nullptr){
                predecessor = predecessor->right;
            }
            predecessor = pt->right;
            predecessor->dad->right = predecessor->left;
            predecessor->left = predecessor->dad;
            predecessor->dad = nullptr;
            delete pt;
        }
        std::cout << "Deleting...\nKey '" << x << "' has been deleted.\n";
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os,Node<T>* node ){
	if (node == nullptr) return os;
	os << node->left << " ";
	os << node->key << " ";
	os << node->right;
	return os;
}

template<typename T>
void freeTree(Node<T>* tree){
	if (tree == nullptr) return;
	freeTree(tree->left);
	freeTree(tree->right);
	delete tree;
}

template<typename T>
Node<T>* enesimo(Node<T> *tree, int n, int it = 1){
	if (tree == nullptr) return nullptr;
	if (it>n) return nullptr;
	enesimo(tree->left, n, it);
	it++;
	if (n==it) return tree;
	enesimo(tree->right,n, it);
}



#endif
