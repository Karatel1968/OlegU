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
    TVal binarySearch(const TArchive<TPair<TKey, TVal>>& data, int target);
    void insertionSort(TArchive<TPair<TKey, TVal>>& data);
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

template<class TKey, class TVal>
TSTable<TKey, TVal>::TSTable(const TArchive<TPair<TKey, TVal>>& data) {
    for (int i = 0; i < data.size(); i++) {

    }

}

template<class TKey, class TVal>
TVal TSTable<TKey, TVal>::binarySearch(const TArchive<TPair<TKey, TVal>>& data, int target) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) {
            return mid;
        }
        if (data[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

template<class TKey, class TVal>
void TSTable<TKey, TVal>::insertionSort(TArchive<TPair<TKey, TVal>>& data) {
    int n = data.size();
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            arr[j + 1] = data[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

#endif //LIB_SORTED_TABLE_