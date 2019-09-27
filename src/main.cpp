#include "../include/binTree.h"
#include <fstream>
#include <sstream>

//template<typename T>
//void buildTree(Node<T>* tree, std::string path){
//std::fstream espec;
//espec.open(path.c_str());
//T val;
//while(espec>>val)
//binTreeInsertion(tree, val);
//}
//
//
//template<typename T>
//void runTest(Node<T>* tree, std::string path){
//
//std::fstream test;
//test.open(path.c_str());
//std::string fcomand;
//while(std::getline(test, fcomand)){
//std::stringstream comand(fcomand);
//std::string func;
//int arg;
//comand >> func;
//
//switch( func ){
//T key;
//
//case "ENESIMO":
			    ///// TODO
//comand >>arg;
//enesimo(tree, arg);
//break;
//case "POSICAO":
			    ///// TODO
//comand >> arg;
//pos(tree, arg);
//break;
//case "MEDIANA":
			    ///// TODO
			    //break;
//case "CHEIA":
			    ///// TODO
			    //break;
//case "COMPLETA":
			    ///// TODO
			    //break;
//case "IMPRIA":
			    ///// Pronto pero no mucho
//std::cout << tree << std::endl;
//break;
//case "INSIRA":
//comand >> key;
//binTreeInsertion(tree, key);
//break;
//case "REMOVA":
//comand >> key;
//binTreeDelete(tree, key);
//break;
//default :
//std::cout << tree << std::endl;
//}
//}
//
//}

int main(){

	int f = 0;
    Node<int> *root = new Node<int>;
    std::cout << "oi" << std::endl;
    binTreeInsertion(root, 20);
    binTreeInsertion(root, 5);
    binTreeInsertion(root, 8);
    binTreeInsertion(root, 7);
    std::cout << root << std::endl;
	Node<int>* it = root;
    binTreeSearch(root, 5, f);
   


	freeTree(root);

	//! Essa função lê o arquivo 1 e constroi a árvore adequada
	// buildTree(root, "path imaginario por enquanto");
	//! Essa função executa os testes presentes no aquivo 2
	//runTest(root, "path imaginario por enquanto");
    return 0;
}
