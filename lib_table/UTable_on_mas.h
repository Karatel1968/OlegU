// Copyright 2024 Urin Oleg

#ifndef LIB_UTABLEONMASS_
#define LIB_UTABLEONMASS_

#include "../lib_list/TList.h"
//#include "../lib_pair/Pair.h"
#include "../lib_table/Table.h"
#include "../lib_dmassive/dmassive.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>

template<class TKey, class TVal>
class UnsortedTableOnMass : public Table<TKey, TVal> {
	TArchive<std::pair<TKey, TVal>> _data;
	size_t _size;
public:
	UnsortedTableOnMass() : _size(0) {}
	UnsortedTableOnMass(const TArchive<std::pair<TKey, TVal>>& data) : _data(data), _size(1) {}
	UnsortedTableOnMass(const UnsortedTableOnMass& tab) : _data(tab._data), _size(tab._size) {};

	TKey insert(TVal value) override;
	void insert(TKey key, TVal val) override;
	void erase(TKey key) override;
	TVal find(TKey key) override;
	int size() override;
	UnsortedTableOnMass& operator=(const UnsortedTableOnMass<TKey, TVal>& tab) noexcept;
};

template<class TKey, class TVal>
int UnsortedTableOnMass<TKey, TVal>::size() {
	return _size;
}

template<class TKey, class TVal>
void UnsortedTableOnMass<TKey, TVal>::erase(TKey key) {
	size_t i = 0;
	for (i = 0; i < _size; i++) {
		if (_data[i].first == key) {
			_data.erase(i, 1);
			return;
		}
	}
	throw std::out_of_range("Key not found");
}


template<class TKey, class TVal>
TVal UnsortedTableOnMass<TKey, TVal>::find(TKey key) {
	for (int i = 0; i < _size; i++) {
		if (_data[i].first == key) {
			return _data[i].second;
		}
	}
	throw std::logic_error("The key is not found");
}

template<class TKey, class TVal>
void UnsortedTableOnMass<TKey, TVal>::insert(TKey key, TVal val) {
	std::pair<TKey, TVal> new_row(key, val);
	_data.push_back(new_row);
	_size++;
}

template<class TKey, class TVal>
TKey UnsortedTableOnMass<TKey, TVal>::insert(TVal value) {
	int key = rand() % 100 + 1;
	std::pair<TKey, TVal> new_row(key, value);
	_data.push_back(new_row);
	_size++;
	return key;
}

template<class TKey, class TVal>
UnsortedTableOnMass<TKey, TVal>& UnsortedTableOnMass<TKey, TVal>::operator=(const UnsortedTableOnMass<TKey, TVal>& tab) noexcept {
	if (this != &tab) {
		_data = tab._data;
		_size = tab._size;
	}
	return *this;
}


#endif  // LIB_UTABLEONMASS_