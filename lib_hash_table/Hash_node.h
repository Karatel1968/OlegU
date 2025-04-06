// Copyright 2024 Urin Oleg

#ifndef LIB_HASH_NODE_
#define LIB_HASH_NODE_

//#include "../lib_pair/Pair.h"
#include "../lib_dmassive/dmassive.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>

enum State { empty, busy, deleted };

template<class TKey, class TVal>
class THNode {
	TKey _key;
	TVal _value;
	State _states = empty;

public:
	THNode() = default;
	THNode(TVal val, TKey key) : _value(val), _key(key) {}
	inline State getState() { return _states; };
	inline void setState(State states) { _states = states; };
	inline TVal& value() { return _value };
	inline TKey& key() { return _key };
};


#endif  // LIB_HASH_NODE_