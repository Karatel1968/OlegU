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
	THTableOM(std::string key, TVal val);
	THTableOM(const THTableOM& tab) : _data(tab._data), _states(tab._states), _size(tab._size);

	void insert(std::string key, TVal val);
	void erase(std::string key);
	TVal find(std::string key) noexcept;
	int size() noexcept;
};

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