#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <set>
#include <functional>


template<typename T, typename COMPARE = std::less<T>>
class IndexableSet: std::set<T, COMPARE> {
	int index;

public:
	using container = std::set<T, COMPARE>;
	using container::container;
	using size_type = typename container::size_type;

	size_type size() {
		return this->size();
	};

	bool empty() {
		return this->empty();
	};

	size_type max_size() {
		return this->max_size();
	};

	void push_back(T element) {

		this->insert(element);
	};

	void clear();

	T front() {
		return **this->begin();
	};

	T back() {
		return **this->rend();
	};

	T at(size_type i) {
		if (i < 0)
			i = size() + i;

		if(i > size() || i < 0)
			throw std::out_of_range("index is our of range");
		return this->at(i);
	};

	T operator[](size_type index) {
//		std::cout << "operator " << index;
		return this->at(index);
	};

};

#endif /* INDEXABLESET_H_ */
