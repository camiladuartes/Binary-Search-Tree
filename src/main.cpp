#include "../include/binTree.h"
#include <fstream>
#include <sstream>

template<typename T>
void buildTree(Node<T>* tree, char* path){
	printf("oi mesmo em ");
	std::fstream espec;
	espec.open(path);
	std::cout << "oi mesmo em 2 ";
	T val;
	espec>>val;
	tree->key = val;
	tree->isRoot = true;
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
		T key;

		if (func == "ENESIMO"){
			/// TODO
			comand >>arg;
			std::cout << "Elemento " << arg << " " << nthElement(tree, arg)->key << std::endl;
		}
		else if ( func == "POSICAO"){
			/// TODO
			comand >> arg;
			position(tree, arg);
		}
		else if ( func == "MEDIANA"){
			std::cout<< "Mediana: " <<median(tree) <<std::endl;
			/// TODO
		}
		else if ( func == "CHEIA"){
			std::cout << "Eh cheia "<< isFull(tree) <<std::endl;
		}
		else if ( func == "COMPLETA"){
			std::cout << "Eh completa "<< isComplete(tree) <<std::endl;
		}
		else if ( func == "IMPRIMA"){
			std::cout << tree << std::endl;
		}
		else if ( func == "INSIRA"){
			comand >> key;
			binTreeInsertion(tree, key);
		}
		else if ( func == "REMOVA"){
			comand >> key;
			binTreeRemoval(tree, key);
		}
		else{ 
			std::cout << tree << std::endl;
		}
	}

}

int main(int argc, char* argv[]){

    Node<int> *root = new Node<int>;
	buildTree(root,argv[1]);
	std::cout << root << std::endl;
	runTest(root, argv[2]);
	freeTree(root);
    return 0;
}
