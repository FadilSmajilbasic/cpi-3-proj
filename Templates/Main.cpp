#include "indexableSet.h"
#include <iostream>

int main(int argc, char **argv) {

	indexableSet<int> val{};

	std::cout << val.size() << "\n";


	val.push_back(1);
	val.push_back(2);
	val.push_back(3);
	std::cout << val[-1]<< "\n";

	//std::cout << typeid(val).name();

//	std::cout << "\nspace " << val[-1];
//	std::cout << "\nspace " << val.max_size();

//	std::cout << "test";
}
