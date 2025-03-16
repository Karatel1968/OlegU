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

template<class TKey, class TVal>
int TBSTTable<TKey, TVal>::size() {
    return _size;
}

template<class TKey, class TVal>
TKey TBSTTable<TKey, TVal>::insert(TVal value) {
    int key = rand() % 100 + 1;
    TPair<TKey, TVal> new_row(key, value);
    _data.insert(new_row);
    _size++;
    return key;
}

template<class TKey, class TVal>
void TBSTTable<TKey, TVal>::insert(TKey key, TVal val) {
    /*std::pair<TKey, TVal > pair = std::make_pair(key, val);
    if (find(key) == val) {
        throw std::logic_error("key already exists");
    }
    else {
    _data.insert(pair);
    _size++;
    }*/
    try {
        find(key);
        throw std::logic_error("Key already exists");
    }
    catch (const std::logic_error&) {
        TPair<TKey, TVal> new_row(key, val);
        _data.insert(new_row);
        _size++;
    }
}

template<class TKey, class TVal>
TVal TBSTTable<TKey, TVal>::find(TKey key) {
    TPair<TKey, TVal> pair(key, TVal());
    TBTreeNode<TPair<TKey, TVal>>* res = _data.search(pair);
    if (res != nullptr && res->value().first() == key) {
        return res->value().second();
    }
    throw std::logic_error("Key not found");
}

template<class TKey, class TVal>
void TBSTTable<TKey, TVal>::erase(TKey key) {
    TPair<TKey, TVal> pair(key, TVal());
    _data.erase(pair);
    _size--;
}

template<class TKey, class TVal>
TBSTTable<TKey, TVal>& TBSTTable<TKey, TVal>::operator=(const TBSTTable<TKey, TVal>& tab) noexcept {
    if (this != &tab) {
        _data = tab._data;
        _size = tab._size;
    }
    return *this;
}
#endif //LIB_BINSEARCHTREE_TABLE_