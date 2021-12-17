#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <set>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <iostream>

template<typename T, typename COMPARE = std::less<T>>
class indexableSet: std::set<T, COMPARE> {
	using container = std::set<T, COMPARE>;
	using container::container;
	using size_type = typename container::size_type;

public:

	size_type size() const {
		return container::size();
	}

	bool empty() const {

		return !size();
	}

	size_type max_size() const {
		return container::max_size();
	}

	void push_back(T element) const {
		this->insert(element);
	}

	void clear() const {
		container::clear();
	}

	T front() const {
		if (empty())
			throw std::out_of_range("No element in container");

		T el = *container::begin();
		return el;
	}

	T back() const {
		if (empty())
			throw std::out_of_range("No element in container");

		T el = *container::rbegin();

		return el;
	}

	T at(int i) const {

		if ((i < 0 && std::abs(i) > size()) || (i >= 0 && std::abs(i) >= size()))
			throw std::out_of_range("index is our of range");

		i = i < 0 ? size() + i : i;

		auto it = container::begin();
		for (int k = 0; k < i; k++) {
			it++;
		}

		return *it;

	}

	T operator[](int index) const {
		T result = (T) at(index);
		return result;
	}

	typename container::reverse_iterator rbegin() const {
		if (empty())
			throw std::out_of_range("No element in container");

		return container::rbegin();
	}
	typename container::reverse_iterator rend() const {
		if (empty())
			throw std::out_of_range("No element in container");

		return container::rend();
	}

	typename container::iterator begin() const {
		if (empty())
			throw std::out_of_range("No element in container");

		return container::begin();
	}

	typename container::iterator end() const {
		if (empty())
			throw std::out_of_range("No element in container");

		return container::end();
	}

};

#endif /* INDEXABLESET_H_ */
