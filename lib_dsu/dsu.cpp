// Copyright 2024 Urin Oleg

#ifndef LIB_DSU_
#define LIB_DSU_

#include "../lib_list/TNode.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

class DSU {
	int _size;
	int* _parent;
	int* _rank;

public:
	DSU(int size = 0);
	~DSU();
	void make_set(int elem);
	int find(int elem);
	void Union(int first, int second);
	void clear();
	int print(int index) {
		return _parent[index];
		/*for (int i = 0; i < _size; i++) {
			std::cout << _parent[i] + 1, ", ";
		}*/
	};
};

DSU::DSU(int size) : _size(size), _parent(new int[size]), _rank(new int[size]()) {
	for (int i = 0; i < size; i++) {
		_parent[i] = i;
	}
}

DSU::~DSU() {
	_size = 0;
	delete[] _parent, _rank;
};

int DSU::find(int elem) {
	if (elem <= 0 || elem > _size) {
		throw std::logic_error("Input Error: ...\n");
	}
	elem--;
	if (_parent[elem] == elem) { return elem + 1; }
	return find(_parent[elem]);
}

void DSU::make_set(int elem) {
	_parent[elem-1] = elem-1;
	_size++;
}

void DSU::Union(int first, int second) {
	int rep = find(first);

	_parent[second - 1] = rep;
}

#endif  // LIB_DSU_