#include "cute/cute.h"
#include "cute/ide_listener.h"
#include "cute/xml_listener.h"
#include "cute/cute_runner.h"

#include "indexableSet.h"
#include <functional>
#include <iostream>

void check() {
	IndexableSet<int,std::less<int>> val{1,2,3};
	std::cout << typeid(val).name();
//	ASSERT(val[0] == 1);
	ASSERT_EQUAL(1,val[0]);
	ASSERT_EQUAL(3,val[-1]);

	//ASSERT(val[-1] == 3);

}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(check));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

//int main(int argc, char const *argv[]) {
//	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
//}
