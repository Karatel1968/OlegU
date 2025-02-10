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
};

DSU::DSU(int size = 0) {
	for (int i = 0; i < size; i++) {
		_parent[i] = i;
	}
}

void DSU::make_set(int elem) {
	_parent[elem-1] = elem-1;
	_size++;
}

#endif  // LIB_DSU_