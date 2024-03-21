#include "Stack.h"

#include <stdexcept>

template <typename T> void Stack<T>::push (T value) {
    if(!data) data = new T[maxSize];
    if (currentSize == maxSize * 0.8) resize (maxSize * 2);
    data[currentSize++] = value;
}

template <typename T> T Stack<T>::pop () {
    if (isEmpty ()) {
        throw std::runtime_error ("Stack is empty");
    }
    return data[--currentSize];
}

template <typename T>
T Stack<T>::peek () {
    return data[currentSize - 1];
}