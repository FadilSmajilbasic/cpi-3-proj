#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <set>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <iostream>

template<typename T, typename COMPARE = std::less<T>>
class indexableSet: std::set<T, COMPARE> {
	int index;

public:
	using container = std::set<T, COMPARE>;
	using container::container;
	using size_type = typename container::size_type;

	size_type size() {
		return container::size();
	};

	bool empty() {
		return container::empty();
	};

	size_type max_size() {
		return container::max_size();
	};

	void push_back(T element) {

		this->insert(element);
	};

	void clear();

	T front() {
		return *container::begin();
	};

	T back() {
		return *container::rend();
	};

	T at(int i) {

		if(i >= 0){
			if(i > size())
				throw std::out_of_range("index is our of range");
			auto it = container::begin();
			for(int k = 0; k <= i; k++){
				it++;
			}
			return *it;
		}
		else{
			i = size() + i;
			if(i > size())
				throw std::out_of_range("index is our of range");
			auto rit = container::begin();
			for(int k = 0; k <= i; k++){
				rit++;
			}
			return *rit;
		}

	};

	T operator[](int index) {
//		std::cout << "operator " << index;
		return this->at(index);
	};

};

#endif /* INDEXABLESET_H_ */
