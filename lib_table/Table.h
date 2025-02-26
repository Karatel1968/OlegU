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
protected:
	Table(Table const&);
	Table(TKey, TVal);
	Table();
public:
	virtual TKey insert(TVal value) = 0;
	virtual void insert(TKey key, TVal val)=0;
	virtual void erase(TKey key)=0;
	virtual TVal& find(TKey key)=0;
	virtual int size() = 0;
};

#endif  // LIB_TABLE_