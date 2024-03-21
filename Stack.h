#ifndef STACK_H
#define STACK_H

template <typename T> class Stack {
    public:
    Stack () : data (nullptr) {
    }
    Stack (int maxLength) : data (new T[maxLength]), maxSize (maxLength) {
    }

    ~Stack () {
        delete[] data;
    }

    void push (T value);
    T pop ();
    T peek ();

    bool isEmpty () {
        return currentSize == 0;
    }

    int getSize () {
        return currentSize;
    }

    private:
    T* data;
    int currentSize = 0;
    int maxSize     = 10;

    void resize (int newMaxSize) {
        T* newData = new T[newMaxSize];
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data    = newData;
        maxSize = newMaxSize;
    }
};

#endif
