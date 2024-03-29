#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <ostream>
#include <queue>

template <typename T>
struct Node {
    T key;
    int height = 1;
    bool isRoot = false;
	int nodesR = 0;
    int nodesL = 0;
    Node<T> *left;
    Node<T> *right;
    Node<T> *dad;
};

template <typename T>
Node<T>*& binTreeSearch(Node<T> *&pt, T x){
    if(pt != nullptr){
        if(pt->key == x){
            return pt;
        }
        else if(pt->key > x){
            return binTreeSearch(pt->left, x);
        }
        else{
            return binTreeSearch(pt->right, x);
        }
    }
    else{
        return pt;
    }
}

template<typename T>
void updateHeight(Node<T> *node){
    // enquanto não chegar na raíz
    while(node->isRoot == false){
        if(node->height+1 > node->dad->height)
            node->dad->height = node->height+1;
        node = node->dad;
    }
}

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
            std::cout << "Adding... Key '" << x << "' has been added!" << std::endl;
            // atualizando altura
            updateHeight(pt->left);
            // atualizando nodesL
            Node<T> *node = pt->left;
            while(node->isRoot == false){
                if(node->dad->left == node)
                    node->dad->nodesL++;
                else
                    node->dad->nodesR++;
                node = node->dad;
            }
            return;
        }
		binTreeInsertion(pt->left, x);
	}
	else {
		if ( pt->right == nullptr){
			pt->right = new Node<T>;
			pt->right->key = x;
			pt->right->dad = pt;
			std::cout << "Adding... Key '" << x << "' has been added!" << std::endl;
			// atualizando altura
            updateHeight(pt->right);
            // atualizando nodesR
            Node<T> *node = pt->right;
            while(node->isRoot == false){
                if(node->dad->right == node)
                    node->dad->nodesR++;
                else
                    node->dad->nodesL++;
                node = node->dad;
            }
            return;
		}
		binTreeInsertion(pt->right, x);
	}
}

template <typename T>
void binTreeRemoval(Node<T> *&pt, T x){
    auto pt_s = binTreeSearch(pt, x);
	if (pt_s == nullptr) return;
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
	if (node->left != nullptr) 
		os << node->left << " ";
	os << node->key << " ";
	if (node->right != nullptr) 
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
Node<T>* nthElement(Node<T> *tree, int n){
    // se tiver que percorrer n+1 noś à esquerda, já está no enésimo nó
	if ( tree->nodesL + 1 == n) return tree;
    // se tiver mais nós pra esquerda do que n, procura essa posição na subárvore da esquerda
	if ( tree->nodesL >= n) return nthElement(tree->left, n);
    // menos nós pra esquerda do que n
	else return nthElement(tree->right, n - 1 - tree->nodesL);	
}


template<typename T>
int position(Node<T>* tree, T element) {
	if ( tree == nullptr ) return 0;
	if ( tree->key == element ) return 1 + tree->nodesL;
	if ( tree->key > element )
		return position(tree->left, element);
	else
		return tree->nodesL + position(tree->right, element) + 1;
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
bool isComplete (Node<T>* root, unsigned int number_nodes, unsigned int index = 0) { 
    if (root == nullptr) 
        return (true); 
  
    if (index >= number_nodes) 
        return (false); 
  
    return (isComplete(root->left, 2*index + 1, number_nodes) && 
            isComplete(root->right, 2*index + 2, number_nodes)); 
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

template<typename T>
T median(Node<T>* tree){
    int numNodes = tree->nodesL + tree->nodesR + 1;
    if(numNodes % 2 != 0){
        return nthElement(tree, (numNodes/2)+1)->key;
    }
    else
        return nthElement(tree, numNodes/2)->key;
}

#endif