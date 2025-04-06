// Copyright 2024 Urin Oleg

#ifndef LIB_HASH_TABLE_OPEN_MIX_
#define LIB_HASH_TABLE_OPEN_MIX_

#include "../lib_pair/Pair.h"
#include "../lib_dmassive/dmassive.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>

enum State { empty, busy, deleted };

template<class TVal>
class THTableOM {
	TPair<std::string, TVal>* _data;
	State* _states;
	int _size = 0;
	int hashFunction(std::string key);
	int SecondHashFunction(std::string key, int h);
public:
	THTableOM() = default;
	THTableOM(int n);
	THTableOM(const THTableOM& tab) : _data(tab._data), _states(tab._states), _size(tab._size) {};

	void insert(std::string key, TVal val);
	void erase(std::string key);
	TVal find(std::string key) noexcept;
	int size() noexcept;
};

template<class TVal>
THTableOM<TVal>::THTableOM(int n) {
	_size = n;
	_data = new TPair<std::string, TVal>[];
	_states = new State[_capacity];

	for (size_t i = 0; i < n; i++) {
		_data[i] = NULL;
		_states[i] = State::empty;
	}
}

template<class TVal>
void THTableOM<TVal>::insert(std::string key, TVal val) {

	hash = hashFunction(key);
	TPair<std::string, TVal> pair(key, val);
	while (true){
		if (_states[hash] == State::busy && _data[hash].first() == key) {
			throw std::logic_error("such element already exists");
		}
		else if (_states[hash] == State::empty || _states[hash] == State::deleted) {
			_data[hash] = pair;
			_states[hash] = State::busy;
			return;
		}
		else {
			int hash = SecondHashFunction(key, hash);
		}
	}
}

template<class TVal>
void THTableOM<TVal>::erase(std::string key) {
	try {
		find(key);
		hash = hashFunction(key);
		_states[hash] = State::deleted;
	}
	catch (...)
	{
		throw std::logic_error("there is no such element in the table");
	}
}

template<class TVal>
int THTableOM<TVal>::hashFunction(std::string key) {
	int sum = 0;
	for (char ch : key) {
		sum += static_cast<int>(ch);
	}
	int hash = sum % _size;
	return hash;
}

template<class TVal>
int THTableOM<TVal>::SecondHashFunction(std::string key, int h) {
	int N = _size / 2;
	int a = _size;
	while(a != 1){
		while (N != 0) {
			int temp = N;
			N = a % N;
			a = temp;
		}
		if (a != 1) {
			N++;
		}
	}

	int hash = (h + N) % _size;

	return hash;
}



#endif  // LIB_HASH_TABLE_OPEN_MIX_