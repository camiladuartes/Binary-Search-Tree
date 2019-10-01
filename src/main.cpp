#include "../include/binTree.h"
#include <fstream>
#include <sstream>

template<typename T>
void buildTree(Node<T>* tree, std::string path){
	std::fstream espec;
	espec.open(path.c_str());
	T val;
	while(espec>>val)
	binTreeInsertion(tree, val);
}


template<typename T>
void runTest(Node<T>* tree, std::string path){

	std::fstream test;
	test.open(path.c_str());
	std::string fcomand;
	while(std::getline(test, fcomand)){
		std::stringstream comand(fcomand);
		std::string func;
		int arg;
		comand >> func;

		switch( func ){
			T key;

			case "ENESIMO":
				/// TODO
				comand >>arg;
				enesimo(tree, arg);
				break;
			case "POSICAO":
				/// TODO
				comand >> arg;
				pos(tree, arg);
				break;
			case "MEDIANA":
				/// TODO
				break;
			case "CHEIA":
				std::cout << ehCheia(tree) <<std::endl;
				break;
			case "COMPLETA":
				std::cout << ehCompleta(tree) <<std::endl;
				break;
			case "IMPRIA":
				std::cout << tree << std::endl;
				break;
			case "INSIRA":
				comand >> key;
				binTreeInsertion(tree, key);
				break;
			case "REMOVA":
				comand >> key;
				binTreeDelete(tree, key);
				break;
			default :
				std::cout << tree << std::endl;
		}
	}

}

int main(){

	int f = 0;
    Node<int> *root = new Node<int>;
	root->key = 19;
    binTreeInsertion(root, 20);
	binTreeInsertion(root, 20);
    binTreeInsertion(root, 5);
    binTreeInsertion(root, 8);
    binTreeInsertion(root, 7);

    std::cout << "Tree: " << root << std::endl;

    binTreeSearch(root, 20);
	binTreeSearch(root, 19);
	binTreeSearch(root, 5);
	binTreeSearch(root, 8);
	binTreeSearch(root, 7);
	binTreeSearch(root, 1);

	std::cout << "ehCheia :"<< ehCheia(root) <<std::endl;
   
	binTreeRemoval(root, 19);
	binTreeRemoval(root, 20);
	binTreeRemoval(root, 5);
	binTreeSearch(root, 7);
	binTreeSearch(root, 19);
	std::cout << "Tree: " << root << std::endl;

	freeTree(root);

	//! Essa função lê o arquivo 1 e constroi a árvore adequada
	// buildTree(root, "path imaginario por enquanto");
	//! Essa função executa os testes presentes no aquivo 2
	//runTest(root, "path imaginario por enquanto");
    return 0;
}
