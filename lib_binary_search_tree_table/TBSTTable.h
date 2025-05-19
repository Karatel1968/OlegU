// Copyright 2024 Urin Oleg

#ifndef LIB_BINSEARCHTREE_TABLE_
#define LIB_BINSEARCHTREE_TABLE_
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include "../lib_binary_search_tree/TBinSearchTree.h"
#include "../lib_table/Table.h"
#include "../lib_binary_search_tree/BTreeNode.h"
#include "../lib_pair/pair.h"

template<class TKey, class TVal>
class TBSTTable : public Table<TKey, TVal> {
    TBinSearchTree<TPair<TKey, TVal>> _data;
    size_t _size;
public:
    TBSTTable() : _size(0) {}
    TBSTTable(const TBinSearchTree<TPair<TKey, TVal>>& data) : _data(data), _size(1) {}
    TBSTTable(const TBSTTable& tab) : _data(tab._data), _size(tab._size) {};
    ~TBSTTable() = default;

    TKey insert(TVal value) override;
    void insert(TKey key, TVal val) override;
    void erase(TKey key) override;
    TVal find(TKey key) override;
    int size() override;
    TBSTTable& operator=(const TBSTTable<TKey, TVal>& tab) noexcept;
};


#endif //LIB_BINSEARCHTREE_TABLE_