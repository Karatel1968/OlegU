// Copyright 2024 Urin Oleg

#ifndef LIB_HASH_TABLE_CHAIN_
#define LIB_HASH_TABLE_CHAIN_

#pragma once
#include "../lib_pair/Pair.h"
#include "../lib_list/TList.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <random>

enum state { empty, busy, deleted };

template<class TVal>
class THTableC {
	TList<TPair<std::string, TVal>>* _data;
	state* _states;
	int _size = 0;
	int hashFunction(std::string key);

public:
	THTableC() = default;
	THTableC(int n);
	THTableC(const THTableC& tab) : _data(tab._data), _states(tab._states), _size(tab._size) {};
	~THTableC() = default;

	inline state getState(int i) { return _states[i]; };
	void insert(std::string key, TVal val);
	void erase(std::string key);
	TVal find(std::string key) noexcept;
	inline int size() noexcept { return _size; };
};

template<class TVal>
THTableC<TVal>::THTableC(int n) {
	_size = n;
	_data = new TList<TPair<std::string, TVal>>[n];
	_states = new state[n];

	for (size_t i = 0; i < n; i++) {
		_states[i] = state::empty;
	}
}



#endif // LIB_HASH_TABLE_CHAIN_