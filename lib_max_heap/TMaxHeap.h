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
	void sift_down(size_t i) noexcept;
	void sift_up(size_t i) noexcept;
	void reserve(size_t new_capacity);
public:
	MaxHeap(size_t size = 0) {
		_size = size;
		_capacity = STEP_CAPACITY;
		_data = new TVal[_capacity];

	};
	MaxHeap(size_t n, const TVal* arr) {
		_size = n;
		_capacity = n > STEP_CAPACITY ? n : STEP_CAPACITY;
		_data = new TVal[_capacity];

		for (size_t i = 0; i < n; i++) {
			_data[i] = arr[i];
		}

		max_heapify();
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
	inline TVal maximum() const { return _data[0]; };
	TVal remove_max();
};

template <class TVal>
void MaxHeap<TVal>::emplace(size_t i, TVal val) {
	if (i >= _size) {
		throw std::out_of_range("position is out of range");
	}

	_data[i] = value;

	if (i > 0 && _data[parent(i)] < _data[i]) {
		sift_up(i);
	}
	else {
		sift_down(i);
	}
}

template <class TVal>
TVal MaxHeap<TVal>::remove_max() {
	_data[0] = _data[_size - 1];
	_size--;
	sift_down(0);
}

template <class TVal>
void MaxHeap<TVal>::erase(size_t i) {
	if (_size == 0) {
		throw std::logic_error("heap is empty");
	}
	_data[i] = _data[_size - 1];
	_size--;
	sift_down(i);
}

template <class TVal>
void MaxHeap<TVal>::max_heapify() noexcept {
	for (int i = _size / 2 - 1; i >= 0; --i) {
		sift_down(i);
	}
}

template <class TVal>
void MaxHeap<TVal>::insert(TVal val) noexcept {
	if (_size == _capacity) {
		reserve(_capacity + ((_capacity * 25) / 100));
	}
	_data[_size] = val;
	sift_up(_size);
	_size++;
}

template <class TVal>
void MaxHeap<TVal>::sift_down(size_t i) noexcept {
	size_t j;
	while (left(i) < _size) {
		if (_data[left(i)] >= _data[right(i)]) {
			j = left(i);
		}
		else {
			j = right(i);
		}
		if (_data[i] <= _data[j]) {
			std::swap(_data[i], _data[j]);
			i = j;
		}
		else {
			break;
		}
	}
}

template <class TVal>
void MaxHeap<TVal>::sift_up(size_t i) noexcept {
	//size_t p = parent(i);
	while (i > 0 && _data[parent(i)] < _data[i]) {
		std::swap(_data[parent(i)], _data[i]);
		i = parent(i);
	}
}

template <class TVal>
void MaxHeap<TVal>::reserve(size_t new_capacity) {

	if (new_capacity <= STEP_CAPACITY) {
		return;
	}

	TVal* new_data = new TVal[new_capacity];

	for (size_t i = 0; i < _size; ++i) {
		new_data[i] = _data[i];
	}

	delete[] _data;

	_data = new_data;
	_capacity = new_capacity;
}

#endif  // LIB_MAX_HEAP_

