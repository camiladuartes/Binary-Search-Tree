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
void runTest(Node<T> tree, std::string path){

	std::fstream test;
	test.open(path.c_str());
	std::string fcomand;
	while(std::getline(test, fcomand)){
		std::stringstream comand(fcomand);
		std::string func, arg;
		comand >> func;

		switch( func ){

		case "Enesimo":
			/// TODO
			comand>>arg;
			break;
		case "POSICAO":
			/// TODO
			comand>> arg;
			break;
		case "MEDIANA":
			/// TODO
			break;
		case "CHEIA":
			/// TODO
			break;
		case "COMPLETA":
			/// TODO
			break;
		case "TO_STRING":
			/// Pronto 
			std::cout << tree << std::endl;
			break;
		}
	}

}

int main(){
    Node<int> *root{nullptr};
    binTreeSearch(root, 2, 0);
    std::cout << std::endl;

    binTreeInsertion(root, 20, 0);
    binTreeSearch(root, 20, 0);
    std::cout << root << std::endl;
	std::cout << "oi meu chapa" << std::endl;

    binTreeInsertion(root, 5, 0);
    binTreeSearch(root, 5, 0);


	freeTree(root);

	//! Essa função lê o arquivo 1 e constroi a árvore adequada
	// buildTree(root, "path imaginario por enquanto");


	//! Essa função executa os testes presentes no aquivo 2
	//runTest(root, "path imaginario por enquanto");
    return 0;
}
