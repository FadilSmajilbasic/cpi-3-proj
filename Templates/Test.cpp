#include "cute/cute.h"
#include "cute/ide_listener.h"
#include "cute/xml_listener.h"
#include "cute/cute_runner.h"

#include "indexableSet.h"
#include <functional>
#include <iostream>
#include <stdexcept>

indexableSet<int> getSet() {
	indexableSet<int> set { 1, 2, 3 };
	return set;
}

void test_istantiation() {
	auto val = getSet();
	ASSERT_EQUAL(1, val[0]);
}

void test_last_value_in_collection() {
	auto val = getSet();
	ASSERT_EQUAL(3, val[-1]);
}

void test_empty_set() {
	indexableSet<int> set { };

	ASSERT(set.empty() && !set.size());
}

void test_exception_positive_index() {
	auto val = getSet();
	ASSERT_THROWS(val[3], std::out_of_range);
}

void test_exception_negative_index() {
	auto val = getSet();

	ASSERT_THROWS(val[-4], std::out_of_range);
}

void test_front(){
	auto val = getSet();
	ASSERT_EQUAL(1,val.front());

}
void test_back(){
	auto val = getSet();
	ASSERT_EQUAL(3,val.back());

}

void test_negative_limit_as_index(){
	auto val = getSet();
	ASSERT_EQUAL(val[0],val[-val.size()]);
}

void test_istantiation_with_different_comparator(){
	auto val = indexableSet<int,std::greater<int>>{1,2,3};

	ASSERT_EQUAL(1,val[2]);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_istantiation));
	s.push_back(CUTE(test_last_value_in_collection));
	s.push_back(CUTE(test_empty_set));
	s.push_back(CUTE(test_exception_positive_index));
	s.push_back(CUTE(test_exception_negative_index));
	s.push_back(CUTE(test_front));
	s.push_back(CUTE(test_back));
	s.push_back(CUTE(test_negative_limit_as_index));
	s.push_back(CUTE(test_istantiation_with_different_comparator));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
