/*
 * File Name: iterator.cpp
 * Assignment: Lab 3 Exercise B
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

// Based on the Vector and VectIter starter code supplied for Lab 3.
#include <cassert>
#include <cstring>
#include <iostream>
#include "mystring2.h"
using namespace std;

template <class T>
class Vector {
public:
    class VectIter {
    private:
        Vector<T>* v;
        int index;
    public:
        explicit VectIter(Vector<T>& x);
        T operator++();
        T operator++(int);
        T operator--();
        T operator--(int);
        T operator*() const;
    };

    explicit Vector(int sz);
    Vector(const Vector<T>& source);
    Vector<T>& operator=(const Vector<T>& rhs);
    ~Vector();
    T& operator[](int i);
    const T& operator[](int i) const;
    void ascending_sort();
private:
    T* array;
    int size;
    void swap(T& a, T& b);
};

template <class T>
Vector<T>::Vector(int sz) : array(nullptr), size(sz) {
    assert(sz >= 0);
    array = new T[sz]();
}

template <class T>
Vector<T>::Vector(const Vector<T>& source)
    : array(new T[source.size]), size(source.size) {
    try {
        for (int i = 0; i < size; i++)
            array[i] = source.array[i];
    } catch (...) {
        delete[] array;
        throw;
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
    if (this != &rhs) {
        Vector<T> copy(rhs);
        T* oldArray = array;
        array = copy.array;
        copy.array = oldArray;
        int oldSize = size;
        size = copy.size;
        copy.size = oldSize;
    }
    return *this;
}

template <class T>
Vector<T>::~Vector() { delete[] array; }

template <class T>
T& Vector<T>::operator[](int i) {
    assert(i >= 0 && i < size);
    return array[i];
}

template <class T>
const T& Vector<T>::operator[](int i) const {
    assert(i >= 0 && i < size);
    return array[i];
}

template <class T>
void Vector<T>::swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
void Vector<T>::ascending_sort() {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (array[i] > array[j])
                swap(array[i], array[j]);
}

// C strings need content comparison; comparing pointers sorts addresses.
template <>
void Vector<const char*>::ascending_sort() {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (strcmp(array[i], array[j]) > 0)
                swap(array[i], array[j]);
}

template <>
void Vector<char*>::ascending_sort() {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (strcmp(array[i], array[j]) > 0)
                swap(array[i], array[j]);
}

template <class T>
Vector<T>::VectIter::VectIter(Vector<T>& x) : v(&x), index(0) {
    // A circular iterator needs at least one element.
    assert(v->size > 0);
}

template <class T>
T Vector<T>::VectIter::operator*() const { return v->array[index]; }

template <class T>
T Vector<T>::VectIter::operator++() {
    index++;
    if (index == v->size)
        index = 0;
    return v->array[index];
}

template <class T>
T Vector<T>::VectIter::operator++(int) {
    T value = v->array[index];
    ++(*this);
    return value;
}

template <class T>
T Vector<T>::VectIter::operator--() {
    index--;
    if (index < 0)
        index = v->size - 1;
    return v->array[index];
}

template <class T>
T Vector<T>::VectIter::operator--(int) {
    T value = v->array[index];
    --(*this);
    return value;
}

int main() {
    Vector<int> x(3);
    x[0] = 999;
    x[1] = -77;
    x[2] = 88;
    Vector<int>::VectIter iter(x);

    cout << "The first element of vector x contains: " << *iter << endl;

#if 1
    cout << "\nTesting an <int> Vector:" << endl;
    cout << "\nTesting sort and postfix ++:" << endl;
    x.ascending_sort();
    assert(x[0] == -77 && x[1] == 88 && x[2] == 999);
    for (int i = 0; i < 3; i++)
        cout << iter++ << endl;

    cout << "\nTesting prefix --:" << endl;
    for (int i = 0; i < 3; i++)
        cout << --iter << endl;

    cout << "\nTesting prefix ++:" << endl;
    for (int i = 0; i < 3; i++)
        cout << ++iter << endl;

    cout << "\nTesting postfix --:" << endl;
    for (int i = 0; i < 3; i++)
        cout << iter-- << endl;

    cout << "\nTesting a <Mystring> Vector:" << endl;
    Vector<Mystring> y(3);
    y[0] = "Bar";
    y[1] = "Foo";
    y[2] = "All";
    Vector<Mystring>::VectIter iters(y);

    cout << "\nTesting sort and postfix ++:" << endl;
    y.ascending_sort();
    assert(y[0] == "All" && y[1] == "Bar" && y[2] == "Foo");
    for (int i = 0; i < 3; i++)
        cout << iters++ << endl;

    cout << "\nTesting prefix --:" << endl;
    for (int i = 0; i < 3; i++)
        cout << --iters << endl;

    cout << "\nTesting prefix ++:" << endl;
    for (int i = 0; i < 3; i++)
        cout << ++iters << endl;

    cout << "\nTesting postfix --:" << endl;
    for (int i = 0; i < 3; i++)
        cout << iters-- << endl;

    cout << "\nTesting a <const char*> Vector:" << endl;
    Vector<const char*> z(3);
    z[0] = "Orange";
    z[1] = "Pear";
    z[2] = "Apple";
    Vector<const char*>::VectIter iterchar(z);

    cout << "\nTesting sort and postfix ++:" << endl;
    z.ascending_sort();
    assert(strcmp(z[0], "Apple") == 0);
    assert(strcmp(z[1], "Orange") == 0);
    assert(strcmp(z[2], "Pear") == 0);
    for (int i = 0; i < 3; i++)
        cout << iterchar++ << endl;

    cout << "\nTesting prefix --:" << endl;
    for (int i = 0; i < 3; i++)
        cout << --iterchar << endl;

    cout << "\nTesting prefix ++:" << endl;
    for (int i = 0; i < 3; i++)
        cout << ++iterchar << endl;

    cout << "\nTesting postfix --:" << endl;
    for (int i = 0; i < 3; i++)
        cout << iterchar-- << endl;
#endif

    cout << "\nProgram terminated successfully." << endl;
    return 0;
}
