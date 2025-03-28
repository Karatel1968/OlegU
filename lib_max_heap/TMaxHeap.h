// Copyright 2024 Urin Oleg

#ifndef LIB_MAX_HEAP_
#define LIB_MAX_HEAP_

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <queue>

#define STEP_CAPACITY 15

template <class TVal>
class MaxHeap {
	TVal* _data;
	size_t _capacity, _size;

	void max_heapify() noexcept;
	void sift_down(size_t) noexcept;
	void sift_up(size_t) noexcept;
public:
	MaxHeap(size_t size = 0) {
		_size = size;
		_capacity = STEP_CAPACITY;
		_data = new T[_capacity];

	};
	MaxHeap(size_t n, const TVal* arr) {
		_size = n;
		_capacity = n > STEP_CAPACITY ? n : STEP_CAPACITY;
		_data = new T[_capacity];

		for (size_t i = 0; i < n; i++) {
			_data[i] = arr[i];
		}
	};
	
	inline size_t lelt(size_t) const;
	inline size_t right(size_t) const;
	inline size_t parent(size_t) const;
	inline bool is_empty() const noexcept;
	void insert(TVal) noexcept;
	void erase(size_t);
	void emplace(size_t, TVal);
	inline TVal max() const;
	TVal remove_max();
};

template <class TVal>
inline size_t MaxHeap<TVal>::lelt(size_t) const {

};

#endif  // LIB_MAX_HEAP_

