#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <ostream>

template <typename T>
struct Node {
    T key;
    int height;
    bool isRoot = false;
	int nodesR = 0, nodesL = 0;
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
void binTreeInsertion(Node<T> *& pt, int x) {
	if (pt->key == x){
		std::cout <<"Key already exists" <<std::endl;
		return;
	}
	if (pt->key < x ){
		if ( pt->left == nullptr){
			pt->left = new Node<T>;
			pt->left->key = x;
			pt->left->dad = pt;
			std::cout << "Key added " <<std::endl;
			return;
		}
		pt->nodesL++;
		binTreeInsertion(pt->left, x);
	}
	else {
		if ( pt->right == nullptr){
			pt->right = new Node<T>;
			pt->right->key = x;
			pt->right->dad = pt;
			std::cout << "Key added " <<std::endl;
			return;
		}
		pt->nodesR++;
		binTreeInsertion(pt->right, x);
	}
	
}

template<typename T>
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
            Node<T> *pred= pt->left;
            while(pred->right != nullptr){
                pred= pred->right;
            }
			pred->right = pt->right;
			pred->dad->right = pred->left;
			pred->left->dad = pred->dad;
			pred->left = pt->left;
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
