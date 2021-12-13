#include "indexableSet.h"
#include <iostream>

int main(int argc, char **argv) {

	IndexableSet<int> val{};

	std::cout << sizeof(val) << "\n";


	val.push_back(3);

	val.push_back(3);
	val.push_back(3);

	std::cout << sizeof(val) << "\n";

	std::cout << typeid(val).name();

//	std::cout << "\nspace " << val[-1];
//	std::cout << "\nspace " << val.max_size();

//	std::cout << "test";
}
