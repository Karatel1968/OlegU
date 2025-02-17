// Copyright 2024 Urin Oleg

#ifndef LIB_TABLE_
#define LIB_TABLE_

#include "../lib_list/TList.h"
#include "../lib_pair/Pair.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

template <class TKey, class TVal>
class Table {
	Table(Table const&);
	Table(TKey, TVal);
	Table();
	virtual TKey insert(TVal value) = 0;
	virtual void insert(TKey key, TVal value)=0;
	virtual void erase(TKey key)=0;
	virtual TVal& find(TKey key)=0;
};

//template <class TKey, class TVal>
//void Table<TKey, TVal>::insert(TKey key, TVal value) {
//	TPair<TKey, TVal> new_row(key, val);
//}

template<class TKey, class TVal>
class UnsortedTable : Table<TKey, TVal> {
	TList<TPair<TKey, TVal>> _data;
	size_t _size;
public:
	TKey insert(TVal value);
};

template<class TKey, class TVal>
TKey UnsortedTable<TKey, TVal>::insert(TVal value) {
	TPair<TKey, TVal> new_row(generate_key, val);
	_data.push_back(new_row);
	_size++;
	reurn new_key;
}


#endif  // LIB_TABLE_