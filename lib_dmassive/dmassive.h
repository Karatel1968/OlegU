#pragma once
#define STEP_CAPACITY 15

enum State { empty, busy, deleted };

namespace algorithms {
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }
}

template <typename T>
class TArchive {
    T* _data;                  
    State* _states;            
    size_t _capacity;          
    size_t _size;              
    size_t _deleted;           
public:
    TArchive();
    TArchive(const TArchive& archive);
    //TArchive(const T* arr, size_t n);
    //TArchive(size_t n, T value);
    //TArchive(const TArchive& archive, size_t pos, size_t n);

    ~TArchive();

    void print() const noexcept;

    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    //size_t size();
    //size_t capacity();
    //const T* data();

    //void swap(TArchive& archive);

    //TArchive& assign(const TArchive& archive);

    //void clear();
    //void resize(size_t n, T value);
    //void reserve(size_t n);

    //void push_back(T value);             
    //void pop_back();                     
    //void push_front(T value);            
    //void pop_front();                    

    //TArchive& insert(const T* arr, size_t n, size_t pos);
    TArchive& insert(T value, size_t pos);

    //TArchive& replace(size_t pos, T new_value);

    //TArchive& erase(size_t pos, size_t n);
    //TArchive& remove_all(T value);
    //TArchive& remove_first(T value);
    //TArchive& remove_last(T value);
    //TArchive& remove_by_index(size_t pos);

    //size_t* find_all(T value) const noexcept;
    //size_t find_first(T value);
    //size_t find_last(T value);
private:
    //size_t count_value(T value);
};

template <typename T>
TArchive<T>::TArchive() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
TArchive<T>::TArchive(const TArchive& archive) {
    _size = archive._size;
    _capacity = archive._capacity;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = archive._data[i];
    }
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = archive._states[i];
    }
}

template <typename T>
TArchive<T>::~TArchive() {
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TArchive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TArchive<T>::full() const noexcept {
    return _size == _capacity;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(T value, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("Error in function \
\"TArchive<T>& insert(T value, size_t pos)\": wrong position value.");
    }
    /*
    // äåéñòâèÿ ïðè ïåðåïîëíåíèè
    if (this->full()) {
        this->reserve(size_t n);
        // + âíóòðè reserve() èñêëþ÷åíèå, åñëè äîñòèãíåì ìàñèìàëüíî
        // âîçìîæíîãî çíà÷åíèÿ _capacity
    }
    */
    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
    }
    _data[pos] = value;
    _states[pos] = State::busy;
    _size++;
    return *this;
}

template <typename T>
void TArchive<T>::print() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            std::cout << _data[i] << ", ";
        }
    }
}

/*
// ïðèìåð ðåàëèçàöèè ñ âîçâðàòîì ìàññèâà íàéäåííûõ ïîçèöèé
template <typename T>
size_t* TArchive<T>::find_all (T value) const noexcept {
    size_t count = this->count_value(value);
    if (count == 0) { return nullptr; }
    int* found_positions = new int[count + 1];
    found_positions[0] = count;

    // TBD

    return found_positions;
}
*/