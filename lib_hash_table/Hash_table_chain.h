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
	THTableC() : _data(nullptr) {};
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

template<class TVal>
void THTableC<TVal>::insert(std::string key, TVal val) {
	int hash = hashFunction(key);
	TPair<std::string, TVal> pair(key, val);

	for (TList<TPair<std::string, TVal>>::iterator pair = _data[hash].begin(); pair != _data[hash].end(); pair++) {
		if ((*pair).first() == key) {
			throw std::logic_error("element with such key already exists");
		}
	}
	_data[hash].push_back(pair);
	_states[hash] = state::busy;
}

template<class TVal>
void THTableC<TVal>::erase(std::string key) {
	int hash = hashFunction(key);

	for (TList<TPair<std::string, TVal>>::iterator pair = _data[hash].begin(); pair != _data[hash].end(); pair++) {
		if ((*pair).first() == key) {
			TNode<TPair<std::string, TVal>>* node = _data[hash].find((*pair));
			_data[hash].erase(node);
			_states[hash] = state::deleted;
			return;
		}
	}
	throw std::logic_error("there is no such element in the table");
}

template<class TVal>
TVal THTableC<TVal>::find(std::string key) noexcept {
	int hash = hashFunction(key);

	if (_data == nullptr || _data[hash].isEmpty())
	  throw std::logic_error("there is no such element in the table");

	for (TList<TPair<std::string, TVal>>::iterator pair = _data[hash].begin(); pair != _data[hash].end(); pair++) {
		if ((*pair).first() == key) {
			return (*pair).second();
		}
	}
	throw std::logic_error("there is no such element in the table");
}

template<class TVal>
int THTableC<TVal>::hashFunction(std::string key) {
	int sum = 0;
	for (char ch : key) {
		sum += static_cast<int>(ch);
	}
	int hash = sum % _size;
	return hash;
}

#endif // LIB_HASH_TABLE_CHAIN_