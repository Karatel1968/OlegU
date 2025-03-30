#ifndef LIB_MIN_HEAP_
#define LIB_MiN_HEAP_

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
class MinHeap {
	TVal* _data;
	size_t _capacity, _size;

	void min_heapify() noexcept;
	void sift_down(size_t i) noexcept;
	void sift_up(size_t i) noexcept;
	void reserve(size_t new_capacity);
public:
	MinHeap(size_t size = 0) {
		_size = size;
		_capacity = STEP_CAPACITY;
		_data = new TVal[_capacity];

	};
	MinHeap(size_t n, const TVal* arr) {
		_size = n;
		_capacity = n > STEP_CAPACITY ? n : STEP_CAPACITY;
		_data = new TVal[_capacity];

		for (size_t i = 0; i < n; i++) {
			_data[i] = arr[i];
		}

		min_heapify();
	};

	inline void print() const noexcept {
		for (int i = 0; i < _size; i++) {
			std::cout << _data[i] << " ";
		}
		std::cout << std::endl;

	}
	inline size_t capacity() const noexcept { return _capacity; }
	inline TVal data(size_t i) const noexcept { return _data[i]; };
	inline size_t size() const noexcept { return _size; };
	inline size_t left(size_t i) const { return (2 * i + 1); };
	inline size_t right(size_t i) const { return (2 * i + 2); };
	inline size_t parent(size_t i) const { return (i - 1) / 2; };
	inline bool is_empty() const noexcept {
		if (_size == 0) { return true; } return false;
	};
	void insert(TVal val) noexcept;
	void erase(size_t i);
	void emplace(size_t i, TVal val);
	inline TVal minimum() const { return _data[0]; };
	TVal remove_min();
};

#endif  // LIB_MIN_HEAP_