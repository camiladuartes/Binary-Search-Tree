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
			    /// TODO
			    break;
		    case "COMPLETA":
			    /// TODO
			    break;
		    case "IMPRIA":
			    /// Pronto pero no mucho
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
    Node<int> *root{nullptr};
    binTreeSearch(root, 2, f);
    std::cout << std::endl;
    binTreeInsertion(root, 20, f);
    binTreeInsertion(root, 2, f);
    binTreeInsertion(root, 0, f);
    binTreeInsertion(root, 6, f);
    binTreeInsertion(root, 9, f);
    binTreeInsertion(root, 5, f);
    std::cout << root << std::endl;
	Node<int>* it = root;
	std::cout << "Deleting 5" << std::endl;
	binTreeDelete(it, 5);
	std::cout << "oi meu chapa" << std::endl;

    binTreeSearch(root, 5, f);


	freeTree(root);

	//! Essa função lê o arquivo 1 e constroi a árvore adequada
	// buildTree(root, "path imaginario por enquanto");
	//! Essa função executa os testes presentes no aquivo 2
	//runTest(root, "path imaginario por enquanto");
    return 0;
}
