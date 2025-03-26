// Copyright 2024 Urin Oleg

#include "../lib_binary_search_tree_table/TBSTTable.h"

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