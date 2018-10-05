#include  <iostream>

template<class T>
class Vector {
public:

    typedef T *iterator;

    Vector();

    Vector(const Vector<T> &__x);

    Vector(Vector<T> &&__x);

    ~Vector();

    unsigned int capacity() const;

    unsigned int size() const;

    iterator begin();

    iterator end();

    void erase(iterator __pos);

    void erase(iterator __first, iterator __last);

    void push_back(const T &__x);

    void push_back(T && __X);

    void pop_back();

    void reserve(unsigned int capacity);

    void swap(T &a, T &b);

    T & operator[](unsigned int index);

//    TODO think
//     OR
//    Vector<T> &operator=(const Vector<T> &);

//    Vector(Vector &&) = default;

    Vector<T> &operator=(Vector &&x);

private:

    void swap(Vector &_x);

    unsigned int _size;
    unsigned int _capacity;
    T *buffer;
};


template<class T>
Vector<T>::Vector() {
    _capacity = 0;
    _size = 0;
    buffer = 0;
}

template<class T>
Vector<T>::Vector(Vector<T> &&__x) {
    buffer(__x.buffer), size(__x._size);
    __x.buffer = nullptr;
    __x._size = nullptr;
}

// must be copy constructor
template<class T>
Vector<T>::Vector(const Vector<T> &__x) {
    _size = __x._size;
    _capacity = __x._capacity;
    buffer = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        buffer[i] = __x.buffer[i];
}

template<class T>
void Vector<T>::swap(Vector<T> &__x) {
    std::swap(this->_size, __x._size);
    std::swap(this->_capacity, __x._capacity);
    std::swap(this->buffer, __x.buffer);

}

template<class T>
void Vector<T>::erase(iterator __pos) {
    if (__pos + 1 != end())
        std::copy(__pos + 1, end(), __pos);

}

template<class T>
void Vector<T>::erase(iterator __first, iterator __last) {
    if (__first != __last)
        std::copy(__last, end(), __first);
}

template<class T>
void swap(T &a, T &b) {
    a.swap(b);
}

//TODO think
//template<class T>
//Vector<T> &Vector<T>::operator=(const Vector<T> &v) {
//    delete[] buffer;
//    _size = v._size;
//    _capacity = v._capacity;
//    buffer = new T[_size];
//    for (unsigned int i = 0; i < _size; i++)
//        buffer[i] = v.buffer[i];
//    return *this;
//}

// still arguable
template<class T>
Vector<T> &Vector<T>::operator=(Vector &&__x) {
    this->buffer = __x.buffer;
    __x.buffer = nullptr;
    this->_size = __x._size;
  //  __x._size = nullptr;
    return *this;
}


template<class T>
typename Vector<T>::iterator Vector<T>::begin() {
    return buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end() {
    return buffer + size();
}


template<class T>
void Vector<T>::push_back(const T &__x) {
    if (_size >= _capacity)
        reserve(_capacity + 5);
    buffer[_size++] = __x;
}

template<class T>
void Vector<T>::push_back(T && __X){
    if (_size >= _capacity)
        reserve(_capacity + 5);
    buffer[_size++]=std::move(__X);
        
}

template<class T>
void Vector<T>::pop_back() {
    _size--;
}

template<class T>
T& Vector<T>::operator[](unsigned int index){
        return buffer[index];
}


template<class T>
void Vector<T>::reserve(unsigned int capacity) {
    if (buffer == 0) {
        _size = 0;
        _capacity = 0;
    }
    T *Newbuffer = new T[capacity];
    unsigned int l_Size = capacity < _size ? capacity : _size;

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = std::move(buffer[i]);

    _capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}

template<class T>
unsigned int Vector<T>::size() const {
    return _size;
}

template<class T>
unsigned int Vector<T>::capacity() const {
    return _capacity;
}

template<class T>
Vector<T>::~Vector() {
    delete[] buffer;
}

