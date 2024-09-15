// Copyright 2024 Urin Oleg

#ifndef LIB_PAIR_PAIR_H_
#define LIB_PAIR_PAIR_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

template <class T1, class T2> class TPair;
template <class T1, class T2>
std::ostream& operator<<(std::ostream& out, const TPair<T1, T2>& obj) noexcept;

template <class T1, class T2>
class TPair {
    T1 _first;
    T2 _second;

      public:
    TPair() : _first(T1()), _second(T2()) { }
    TPair(const T1& first, const T2& second) : \
        _first(first), _second(second) { }
    TPair(const TPair& pair) : _first(pair._first), _second(pair._second) { }
    ~TPair() { }

    inline T1 first() const noexcept;
    inline T2 second() const noexcept;
    inline void set_first(const T1& value) noexcept;
    inline void set_second(const T2& value) noexcept;

    TPair& operator=(const TPair& pair) noexcept;
    bool operator!=(const TPair& pair) const noexcept;
    TPair& operator-=(const TPair& pair);

    TPair<T1, T2> operator+(const TPair<T1, T2>& pair) const noexcept;

    bool operator==(const TPair& pair) const noexcept;

    bool operator<(const TPair& pair) const noexcept;

    bool operator>(const TPair& pair) const noexcept;

    bool operator<=(const TPair& pair) const noexcept;

    bool operator>=(const TPair& pair) const noexcept;

    // friend TPair& operator-\\
    // (const TPair<T1, T2>& pair1,
    // const TPair<T1, T2>& pair2) noexcept;

    // TPair<T1, T2> operator-(const TPair<T1, T2>& other) const noexcept;
    // TPair& operator-(const TPair& pair)const noexcept;
    TPair<T1, T2> operator-(const TPair<T1, T2>& pair) const noexcept;

    std::string to_string() const noexcept;

    friend std::ostream& operator<<<T1, T2>\
        (std::ostream& out, const TPair<T1, T2>& pair) noexcept;

    void swap(TPair& other) noexcept {
        T1 tempF = _first;
        _first = other._first;
        other._first = tempF;

        T2 tempS = _second;
        _second = other._second;
        other._second = tempS;
    }
};

/*template <class T1, class T2>
inline TPair<T1, T2>::TPair(const TPair<T1, T2>& pair) {
    _first = pair._first;
    _second = pair._second;
}*/

template <class T1, class T2>
inline T1 TPair<T1, T2>::first() const noexcept {
    return _first;
}

template <class T1, class T2>
inline T2 TPair<T1, T2>::second() const noexcept {
    return _second;
}

template <class T1, class T2>
inline void TPair<T1, T2>::set_first(const T1& value) noexcept {
    _first = value;
}

template <class T1, class T2>
inline void TPair<T1, T2>::set_second(const T2& value) noexcept {
    _second = value;
}

template <class T1, class T2>
TPair<T1, T2>& TPair<T1, T2>::operator=(const TPair<T1, T2>& pair) noexcept {
    if (this != &pair) {
        _first = pair._first;
        _second = pair._second;
    }
    return *this;
}

template <class T1, class T2>
bool TPair<T1, T2>::operator!=(const TPair<T1, T2>& pair) const noexcept {
    return !(*this == pair);
}

template <class T1, class T2>
TPair<T1, T2>& TPair<T1, T2>::operator-=\
(const TPair<T1, T2>& pair){
    _first -= pair._first;
    _second -= pair._second;
    return *this;
}

template <>
TPair<int, std::string>& TPair<int, std::string>\
::operator-=(const TPair<int, std::string>& pair) {
    // Для целого типа _first можно выполнять вычитание как обычно
    _first -= pair._first;

    // Выбрасываем исключение для строки
    throw std::logic_error\
        ("Операция -= не поддерживается для типа std::string");

    return *this;
}

template <>
TPair<double, std::string>& TPair<double, std::string>\
::operator-=(const TPair<double, std::string>& pair) {
    // Для целого типа _first можно выполнять вычитание как обычно
    _first -= pair._first;

    // Выбрасываем исключение для строки
    throw std::logic_error\
        ("Операция -= не поддерживается для типа std::string");

    return *this;
}

template <>
TPair<std::string, std::string>& TPair<std::string, std::string>\
::operator-=(const TPair<std::string, std::string>& pair) {

    throw std::logic_error\
        ("Операция -= не поддерживается для типа std::string");

    return *this;
}

template <class T1, class T2>
TPair<T1, T2> TPair<T1, T2>::operator+\
(const TPair<T1, T2>& pair) const noexcept {
    TPair<T1, T2> temp(*this);
    temp._first += pair._first;
    temp._second += pair._second;
    return temp;
}

template <class T1, class T2>
bool TPair<T1, T2>::operator==(const TPair& pair) const noexcept {
    if (_first != pair._first) {
        return false;
    } else if (_second != pair._second) {
        return false;
    }
    return true;
}

/*template <class T1, class T2>
bool TPair<T1, T2>::operator==(const TPair& pair) const noexcept {
    return _first == pair._first && _second == pair._second;
}

template <typename T1, typename T2>
bool operator==(const TPair<T1, T2>& lhs, const TPair<T1, T2>& rhs) {
    return lhs.first() == rhs.first() && lhs.second() == rhs.second();
}*/

template <class T1, class T2>
bool TPair<T1, T2>::operator>(const TPair& pair) const noexcept {
    if (_first > pair._first) {
        return true;
    }
    if (_first < pair._first) {
        return false;
    }
    if (_second > pair._second) {
        return true;
    }
    return true;
}

template <class T1, class T2>
bool TPair<T1, T2>::operator<(const TPair& pair) const noexcept {
    if (_first < pair._first) {
        return true;
    }
    if (_first > pair._first) {
        return false;
    }
    if (_second < pair._second) {
        return true;
    }
    return false;
}

template <class T1, class T2>
bool TPair<T1, T2>::operator>=(const TPair& pair) const noexcept {
    if (_first < pair._first) {
        return false;
    }
    if (_second < pair._second) {
        return false;
    }
    return true;
}

template <class T1, class T2>
bool TPair<T1, T2>::operator<=(const TPair& pair) const noexcept {
    if (_first > pair._first) {
        return false;
    }
    if (_second > pair._second) {
        return false;
    }
    return true;
}

/*template <class T1, class T2>
TPair<T1, T2>& operator-\
(const TPair<T1, T2>& pair1, const TPair<T1, T2>& pair2) noexcept {
    TPair<T1, T2> temp;
    temp._first -= pair._first;
    temp._second -= pair._second;
    return temp;
}*/

template <class T1, class T2>
TPair<T1, T2> TPair<T1, T2>::operator-\
(const TPair<T1, T2>& pair) const noexcept {
    TPair<T1, T2> temp;
    temp._first = _first - pair._first;
    temp._second = _second - pair._second;
    return temp;
}


template <class T1, class T2>
std::string TPair<T1, T2>::to_string() const noexcept {
    std::string str = "(" + std::to_string(_first) + \
        ", " + std::to_string(_second) + ")";
    return str;
}

template <class T1, class T2>
std::ostream& operator<< <T1, T2>(std::ostream& out,\
    const TPair<T1, T2>& pair) noexcept {
    out << pair.to_string();
    return out;
}

#endif  // LIB_PAIR_PAIR_H_
