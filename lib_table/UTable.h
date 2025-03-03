// Copyright 2024 Urin Oleg

#ifndef LIB_UTABLE_
#define LIB_UTABLE_

#include "../lib_list/TList.h"
//#include "../lib_pair/Pair.h"
#include "../lib_table/Table.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>

template<class TKey, class TVal>
class UnsortedTable : public Table<TKey, TVal> {
	TList<std::pair<TKey, TVal>> _data;
	size_t _size;
public:
	UnsortedTable() : _size(0) {}
	UnsortedTable(const TList<std::pair<TKey, TVal>>& data) : _data(data), _size(data._size) {}
	UnsortedTable(const UnsortedTable& tab) : _data(tab._data), _size(tab._size) {};

	TKey insert(TVal value) override;
	void insert(TKey key, TVal val) override;
	void erase(TKey key) override;
	TVal find(TKey key) override;
	int size() override;
	UnsortedTable& operator=(const UnsortedTable<TKey, TVal>& tab) noexcept;
};

template<class TKey, class TVal>
int UnsortedTable<TKey, TVal>::size() {
	return _size;
}

template<class TKey, class TVal>
void UnsortedTable<TKey, TVal>::erase(TKey key) {
	/*for (auto& pair : _data) {
		if (pair.first == key) {
			_data.erase(pair);
			--_size;
			return;
		}
	}*/
	/*for (auto it = _data.begin(); it != _data.end(); ++it) {
		if ((*it).first == key) {
			_data.erase(it);
			--_size;
			return;
		}
	}*/
	/*TNode<std::pair<TKey, TVal>>* cur = _data.getHead();

	while (cur != nullptr) {
		if ((*cur).first() == key) {
			_data.erase(cur);
		}
		cur = cur->next();
	}
	throw std::logic_error("The key is not found");*/
}

template<class TKey, class TVal>
TVal UnsortedTable<TKey, TVal>::find(TKey key) {
	for (TList<std::pair<TKey, TVal>>::iterator pair = _data.begin(); pair !=_data.end(); pair++) {
		if ((*pair).first == key) {
			return (*pair).second;
		}
	}
	/*TNode<std::pair<TKey, TVal>>* cur = _data.getHead();

	while (cur != nullptr) {
		if ((*cur).first() == key) {
			return cur.second();
		}
		cur = cur->next();
	}*/
	throw std::logic_error("The key is not found");
}

template<class TKey, class TVal>
void UnsortedTable<TKey, TVal>::insert(TKey key, TVal val) {
	
}

template<class TKey, class TVal>
TKey UnsortedTable<TKey, TVal>::insert(TVal value) {
	int key = rand() % 100 + 1;
	std::pair<TKey, TVal> new_row(key, value);
	_data.push_back(new_row);
	_size++;
	return key;
}

template<class TKey, class TVal>
UnsortedTable<TKey, TVal>& UnsortedTable<TKey, TVal>::operator=(const UnsortedTable<TKey,TVal>& tab) noexcept {
	if (this != &tab) {
		_data = tab._data;
		_size = tab._size;
	}
	return *this;
}


#endif  // LIB_UTABLE_