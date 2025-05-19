// Copyright 2024 Urin Oleg

#ifndef LIB_HASH_TABLE_OPEN_MIX_
#define LIB_HASH_TABLE_OPEN_MIX_

#pragma once
#include "../lib_pair/Pair.h"
//#include "../lib_dmassive/dmassive.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <random>

enum state { empty, busy, deleted };

template<class TVal>
class THTableOM {
	TPair<std::string, TVal>* _data;
	state* _states;
	int _size = 0;
	int hashFunction(std::string key);
	int SecondHashFunction(std::string key, int h);
public:
	THTableOM() = default;
	THTableOM(int n);
	THTableOM(const THTableOM& tab) : _data(tab._data), _states(tab._states), _size(tab._size) {};
	~THTableOM() = default;

	inline state getState(int i) { return _states[i]; };
	inline TPair<std::string, TVal> data(int i) { return _data[i]; };
	void insert(std::string key, TVal val);
	void erase(std::string key);
	TVal find(std::string key);
	inline int size() noexcept { return _size; };
};

template<class TVal>
THTableOM<TVal>::THTableOM(int n) {
	_size = n;
	_data = new TPair<std::string, TVal>[n];
	_states = new state[n];

	for (size_t i = 0; i < n; i++) {
		_states[i] = state::empty;
	}
}

template<class TVal>
TVal THTableOM<TVal>::find(std::string key) {
	int hash = hashFunction(key);
	while (true) {
		if (_states[hash] == state::empty) {
			throw std::logic_error("there is no such element in the table");
			return TVal();
		}
		else if ((_states[hash] == state::busy && key != _data[hash].first()) || _states[hash] == state::deleted) {
			hash = SecondHashFunction(key, hash);
		}
		else {
			return _data[hash].second();
		}
	}
}

template<class TVal>
void THTableOM<TVal>::insert(std::string key, TVal val) {

	int hash = hashFunction(key);
	TPair<std::string, TVal> pair(key, val);
	while (true){
		if (_states[hash] == state::busy && _data[hash].first() == key) {
			throw std::logic_error("element with such key already exists");
		}
		else if (_states[hash] == state::empty || _states[hash] == state::deleted) {
			_data[hash] = pair;
			_states[hash] = state::busy;
			return;
		}
		else {
			hash = SecondHashFunction(key, hash);
		}
	}
}

template<class TVal>
void THTableOM<TVal>::erase(std::string key) {
	int hash = hashFunction(key);
	while (true) {
		if (_states[hash] == state::empty) {
			throw std::logic_error("there is no such element in the table");
		}
		else if ((_states[hash] == state::busy && key != _data[hash].first()) || _states[hash] == state::deleted) {
			int hash = SecondHashFunction(key, hash);
		}
		else {
			_states[hash] = state::deleted;
			return;
		}
	}
	
}

template<class TVal>
int THTableOM<TVal>::hashFunction(std::string key) {
	int sum = 0;
	for (char ch : key) {
		sum += static_cast<int>(ch);
	}
	int hash = sum % _size;
	if (hash < 0) {
		hash = hash * (-1);
	}
	return hash;
}

template<class TVal>
int THTableOM<TVal>::SecondHashFunction(std::string key, int h) {
	/*static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<> dis(2, _size);

	int N = dis(gen);
	int saveN = 0;
	int a = _size;
	while(a != 1){
		saveN = N;
		while (N != 0) {
			int temp = N;
			N = a % N;
			a = temp;
		}
		if (a != 1) {
			N = dis(gen);
		}
	}*/

	int hash = (h + 3) % _size;

	return hash;
}



#endif  // LIB_HASH_TABLE_OPEN_MIX_