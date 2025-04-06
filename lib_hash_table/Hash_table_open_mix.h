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

template<class TKey, class TVal>
class THTableOM {
	TPair<TKey, TVal>* _data;
	State* _states;
	int _size = 0;
	int hashFunction(TKey key);
public:
	THTableOM() = default;
	THTableOM(TKey key, TVal val);
	THTableOM(const THTableOM& tab) : _data(tab._data), _states(tab._states), _size(tab._size);

	void insert(TKey key, TVal val);
	void erase(TKey key);
	TVal find(TKey key) noexcept;
	int size() noexcept;
};

template<class TKey, class TVal>
int THTableOM<TKey, TVal>::hashFunction(TKey key) {

}
#endif  // LIB_HASH_TABLE_OPEN_MIX_