#ifndef LIB_BINSEARCHTREE_TABLE_
#define LIB_BINSEARCHTREE_TABLE_

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include "../lib_binary_search_tree/TBinSearchTree.h"
#include "../lib_table/Table.h"
#include "../lib_binary_search_tree/BTreeNode.h"

template<class TKey, class TVal>
class TBSTTable : public Table<TKey, TVal> {
    TBinSearchTree<std::pair<TKey, TVal>> _data;
    size_t _size;
public:
    TBSTTable() : _size(0) {}
    TBSTTable(const TBinSearchTree<std::pair<TKey, TVal>>& data) : _data(data), _size(1) {}
    TBSTTable(const TBSTTable& tab) : _data(tab._data), _size(tab._size) {};
    ~TBSTable() = default;

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
    std::pair<TKey, TVal> new_row(key, value);
    _data.insert(new_row);
    _size++;
    return key;
}

template<class TKey, class TVal>
void TBSTTable<TKey, TVal>::insert(TKey key, TVal val) {
    std::pair<TKey, TVal >> pair(key, val);
    if (find(pair)->value().second == val) {
        throw std::logic_error("key already exists");
    }
    //std::pair<TKey, TVal> new_row(key, val);
    _data.insert(pair);
    _size++
}

template<class TKey, class TVal>
TVal TBSTTable<TKey, TVal>::find(TKey key) {
    BTreeNode<std::pair<TKey, TVal>>* res = _data.search(std::make_pair(key, TVal()));
    if (res != nullptr && res->value().first == key) {
        return res->value().second;
    }
    throw std::logic_error("Key not found");
}

template<class TKey, class TVal>
void TBSTTable<TKey, TVal>::erase(TKey key) {
    _data.erase(std::make_pair(key, TVal()));
    _size--;
}


#endif //LIB_BINSEARCHTREE_TABLE_