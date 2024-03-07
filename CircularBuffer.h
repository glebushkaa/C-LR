#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include "utils.h"

template<typename T, int Size>
class CircularBuffer {
public:
    CircularBuffer() : tail(0), head(0), count(0) {
        for (int i = 0; i < Size; i++) {
            buffer[i] = 0;
        }
    }

    void push(T element) {
        buffer[tail] = element;
        tail = coerceAtMost(tail + 1, Size) % Size;
        count = coerceAtMost(count + 1, Size);
    }

    int getCurrentSize() {
        return count;
    }

    T pop() {
        if (count >= Size) head = tail % Size;
        T element = buffer[head];
        buffer[head] = 0;
        head = coerceAtMost(head + 1, Size) % Size;
        count = coerceAtLeast(count - 1, 0);
        return element;
    }

    void values(T *array) {
        for (int i = 0; i < count; i++) {
            int index = (head + i) % Size;
            array[i] = buffer[index];
        }
    }

    bool isEmpty() { return head == tail; }

private:
    T buffer[Size];
    int tail;
    int head;
    int count;
};

#endif
