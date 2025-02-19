// Copyright 2024 Urin Oleg

#ifndef LIB_UTABLE_
#define LIB_UTABLE_

#include "../lib_list/TList.h"
#include "../lib_pair/Pair.h"
#include "../lib_table/Table.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

template<class TKey, class TVal>
class UnsortedTable : Table<TKey, TVal> {
	TList<TPair<TKey, TVal>> _data;
	size_t _size;
public:
	UnsortedTable() {}
	UnsortedTable(const TList<TPair<TKey, TVal>>& data) : _data(data) {
		_size = _data.size();
	}
	UnsortedTable(const UTable& tab) : _data(tab._data), _size(tab._size) {};

	TKey insert(TVal value) override;
	void insert(TKey key, TVal val) override;
	void erase(TKey key) override;
	TVal& find(TKey key) override;
	int size() override;
};

template<class TKey, class TVal>
int UnsortedTable<TKey, TVal>::size() {
	return _size;
}

template<class TKey, class TVal>
void UnsortedTable<TKey, TVal>::erase(TKey key) {
	for (auto& pair : _data) {
		if (pair.first() == key) {
			_data.erase(pair);
			_size--;
		}
	}
	if (_size != _size--) {
		throw std::logic_error("The key is not found");
	}
}

template<class TKey, class TVal>
TVal& UnsortedTable<TKey, TVal>::find(TKey key) {
	for (auto& pair : _data) {
		if (pair.first() == key) {
			return pair.second();
		}
	}
	throw std::logic_error("The key is not found");
}

template<class TKey, class TVal>
void UnsortedTable<TKey, TVal>::insert(TKey key, TVal val) {
	if (find(key)) {
		throw std::logic_error("The item with such key is already exists");
	}
	TPair<TKey, TVal> new_row(key, val);
	_data.push_back(new_row);
	_size++;
}

template<class TKey, class TVal>
TKey UnsortedTable<TKey, TVal>::insert(TVal value) {
	int key = rand() % 100 + 1;
	TPair<TKey, TVal> new_row(key, val);
	_data.push_back(new_row);
	_size++;
	reurn new_key;
}

#endif  // LIB_UTABLE_