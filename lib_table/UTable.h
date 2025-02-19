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
	UTable() {}
	UTable(const TList<TPair<Tkey, Tval>>& data) : _data(data) {
		_size = _data.size();
	}
	UTable(const UTable& tab) : _data(tab._data), _size(tab._size) {};

	TKey insert(TVal value) override;
	void insert(Tkey key, Tval val) override;
	void erase(Tkey key) override;
	Tval find(Tkey key) override;
};



template<class TKey, class TVal>
TKey UnsortedTable<TKey, TVal>::insert(TVal value) {
	TPair<TKey, TVal> new_row(generate_key, val);
	_data.push_back(new_row);
	_size++;
	reurn new_key;
}

#endif  // LIB_UTABLE_