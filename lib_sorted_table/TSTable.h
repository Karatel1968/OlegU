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
    int binarySearch(TKey target);
    void insertionSort();
public:
    TSTable() = default;
    TSTable(const TArchive<TPair<TKey, TVal>>& data);
    TSTable(const TSTable& tab) : _data(tab._data) {}
    ~TSTable() = default;

    TKey insert(TVal value) override;
    void insert(TKey key, TVal val) override;
    void erase(TKey key) override;
    TVal find(TKey key) override;
    int size() override;
    TSTable& operator=(const TSTable<TKey, TVal>& tab) noexcept;
};

template<class TKey, class TVal>
int TSTable<TKey, TVal>::size() {
    return _data.size();
}

template<class TKey, class TVal>
TSTable<TKey, TVal>::TSTable(const TArchive<TPair<TKey, TVal>>& data) {
    insertionSort(data);
    _data = data;
}

template<class TKey, class TVal>
int TSTable<TKey, TVal>::binarySearch(TKey target) {
    int left = 0;
    int right = _data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (_data[mid].first() == target) {
            return mid;
        }
        if (_data[mid].first() > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    throw std::logic_error("key not found");
}

template<class TKey, class TVal>
void TSTable<TKey, TVal>::insertionSort() {
    int n = _data.size();
    for (int i = 1; i < n; i++) {
        TPair<TKey, TVal> key = _data[i];
        int j = i - 1;

        while (j >= 0 && _data[j].first() > key.first()) {
            _data[j + 1] = _data[j];
            j = j - 1;
        }
        _data[j + 1] = key;
    }
}

template<class TKey, class TVal>
TKey TSTable<TKey, TVal>::insert(TVal value) {
    int key = rand() % 100 + 1;
    TPair<TKey, TVal> new_row(key, value);
    _data.push_back(new_row);
    insertionSort();
    return key;

}

template<class TKey, class TVal>
void TSTable<TKey, TVal>::insert(TKey key, TVal val) {
    if (_data[binarySearch(key)].second() != val) {
        TPair<TKey, TVal> new_row(key, val);
        _data.push_back(new_row);
        insertionSort();
        return;
    }
    throw std::logic_error("key already exists");
}

template<class TKey, class TVal>
TVal TSTable<TKey, TVal>::find(TKey key) {
    if (_data[binarySearch(key)].first() == key) {
        return _data[binarySearch(key)].second();
    }
    throw std::logic_error("key not found");
}

template<class TKey, class TVal>
void TSTable<TKey, TVal>::erase(TKey key) {
    _data.remove_by_index(binarySearch(key));
}


#endif //LIB_SORTED_TABLE_