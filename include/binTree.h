#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <ostream>
#include <queue>

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
Node<T>*& binTreeSearch(Node<T> *&pt, T x){
    if(pt != nullptr){
        if(pt->key == x){
            std::cout << "Key '" << x << "' was found!\n";
            return pt;
        }
        else if(pt->key > x){
            binTreeSearch(pt->left, x);
        }
        else{
            binTreeSearch(pt->right, x);
        }
    }
    else{
        std::cout << "Key '" << x << "' was not found!\n";
        return pt;
    }
}

//template<typename T>
//void updateHeight(Node<T> tree);

template <typename T>
void binTreeInsertion(Node<T> *& pt, T x) {
	if (pt->key == x){
		std::cout <<"Key '" << x << "' already exists!" << std::endl;
		return;
	}
	if (pt->key > x ){
		if ( pt->left == nullptr){
			pt->left = new Node<T>;
			pt->left->key = x;
			pt->left->dad = pt;
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
			std::cout << "Adding... Key '" << x << "' has been added!" << std::endl;
			return;
		}
		pt->nodesR++;
		binTreeInsertion(pt->right, x);
	}
	
}

template<typename T>
void binTreeRemoval(Node<T> *&pt, T x){
    auto pt_s = binTreeSearch(pt, x);
    if(pt_s->key == x){
        if(pt_s->left == nullptr and pt_s->right == nullptr){ // é folha
            if (pt_s->dad->left->key == x){
                pt_s->dad->left = nullptr;
            }
            else{
                pt_s->dad->right = nullptr;
            }
            delete pt_s;
        }
        else if(pt_s->left != nullptr and pt_s-> right == nullptr){ // tem uma subárvore vazia (1 filho)
            if(pt_s->dad->left->key == x){
                pt_s->dad->left = pt_s->left;
            }
            else{
                pt_s->dad->right = pt_s->left;
            }
            delete pt_s;
        }
        else if(pt_s->left == nullptr and pt_s-> right != nullptr){ // tem uma subárvore vazia (1 filho)
            if(pt_s->dad->left->key == x){
                pt_s->dad->left = pt_s->right;
            }
            else{
                pt_s->dad->right = pt_s->right;
            }
            delete pt_s;
        }
        else if(pt_s->left != nullptr and pt_s->right != nullptr){ // não é folha e tem dois filhos
            Node<T> *pred= pt_s->left;
            while(pred->right != nullptr){
                pred= pred->right;
            }
			pred->right = pt_s->right;
			T aux = pred->key;
            pred->key = pt->key;
            pt->key = aux;
            if(pred->left == nullptr ){ // é folha
                pred->dad->right = nullptr;
                delete pred;
            }  
            else if(pred->left != nullptr){ // tem uma subárvore vazia (1 filho)
                pred->dad->right = pred->left;
                delete pred;
            }
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
Node<T>* nthElement(Node<T> *tree, int n, int it = 1){
	if (tree == nullptr) return nullptr;
	if (it>n) return nullptr;
	nthElement(tree->left, n, it);
	it++;
	if (n==it) return tree;
	nthElement(tree->right,n, it);
}

template<typename T>
bool isFull(Node<T>* tree){
	if (tree == nullptr) return false;
	if (tree->left == tree->right and tree->right == nullptr)
		return true;
	if (tree->left != nullptr and tree->right != nullptr)
		return isFull(tree->left) and isFull(tree->right);
	else
		return false;
}

template<typename T>
bool isComplete(Node<T>* tree) {
	if (tree == nullptr) return false;
	if (tree->left != nullptr and tree->right != nullptr)
		return true;
	if (tree->left != nullptr){
		if (isComplete(tree->left))
			return true;
		else
			return false;
	}
	else{
		if (isComplete(tree->right))
			return true;
		else
			return false;
	}
}

template<typename T>
std::string toString(Node<T>* tree) {
    std::string levelVisitationSequence = "";
    std::queue<Node<T>*> myqueue;
    myqueue.push(tree);
    while(!myqueue.empty()){
        auto aux = myqueue.front();
        levelVisitationSequence += std::to_string(aux->key) + " ";
        if(aux->left != nullptr)
            myqueue.push(aux->left);
        if(aux->right != nullptr)
            myqueue.push(aux->right);
        myqueue.pop();
    }
    return levelVisitationSequence;  
}

// corrigir `nthElement`; fazer `posição`; atualizar altura.

#endif
