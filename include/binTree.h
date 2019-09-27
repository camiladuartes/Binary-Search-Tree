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

template<typename T>
void binTreeDelete(Node<T> *pt, T x,Node<T>* parent = nullptr) {
	if(pt == nullptr) return;

	if( pt->key == x ){
		if( pt->right == pt->left && pt->left == nullptr){
			delete pt;
			return;
		}
		if( pt->right == nullptr || pt->left == nullptr){
			if( pt->right != nullptr ){
				parent->left = pt->left;
				delete pt;
				return;
			}
			else {
				parent->right = pt->right;
				delete pt;
				return;
			}
		}
		else{
			Node<T>* it = pt->right;
			while(it->right != nullptr)
				it = it->right;
			pt->key = it->key;
		}
	}
	else {
		parent = pt;
		if( pt->key > x ){
			std::cout << pt->key <<" > " << x << std::endl;
			std::cout << pt->left->key << std::endl;
			pt = pt->left;
		}
		else{
			std::cout << pt->key <<" < " << x << std::endl;
			pt = pt->right;
		}

		binTreeDelete(pt, x, parent);
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
