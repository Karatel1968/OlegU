// Copyright 2024 Urin Oleg

#ifndef LIB_SORTED_TABLE_
#define LIB_SORTED_TABLE_
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>

#include "../lib_table/Table.h"
#include "../lib_dmassive/dmassive.h"
#include "../lib_pair/pair.h"

template<class TKey, class TVal>
class TSTable : public Table<TKey, TVal> {
	TArchive<TPair<TKey, TVal>> _data;

public:
    TSTable() = default;
    TSTable(const TArchive<TPair<TKey, TVal>>& data);
    TSTable(const TSTable& tab);
    ~TSTable() = default;

    TKey insert(TVal value) override;
    void insert(TKey key, TVal val) override;
    void erase(TKey key) override;
    TVal find(TKey key) override;
    int size() override;
    TSTable& operator=(const TSTable<TKey, TVal>& tab) noexcept;
};




#endif //LIB_SORTED_TABLE_