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
	virtual TKey insert(TVal value);
	virtual void insert(TKey key, TVal value);
	virtual void erase(TKey key);
	virtual TVal& find(TKey key);
};

template <class TKey, class TVal>
void Table<TKey, TVal>::insert(TKey key, TVal value) {
	TPair<TKey, TVal> new_row(key, val);
}


#endif  // LIB_TABLE_