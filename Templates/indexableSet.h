#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <set>
#include <functional>
#include <stdexcept>

template<typename T, typename COMPARE = std::less<T>>
class IndexableSet: std::set<T, COMPARE> {
	int index;

public:
	int size() {
		return this->size();
	}
	;
	bool empty() {
		return this->empty();
	}
	;
	int max_size() {
		return this->max_size();
	}
	;
	void push_back(T element) {
		this->insert(element);

	}
	;
	void clear();

	T front() {
		return **this->begin();
	}
	;
	T back() {
		return **this->rend();
	}
	;
	T at(int i) {
		if (i < 0)
			i = size() + i;

		if(i > size() || i < 0)
			throw std::out_of_range("index is our of range");
		return this->at(i);
	}
	;

	using container = std::set<T>;
	using container::container;
	using size_type = typename container::size_type;

	T operator[](size_type index) {
		return this->at(index);
	}

};

#endif /* INDEXABLESET_H_ */
