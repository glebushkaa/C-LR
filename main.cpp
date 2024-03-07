#include "CircularBuffer.h"
#include <iostream>
using namespace std;

void printBuffer(int *buffer, int size);

int main() {
    CircularBuffer<int, 5> buffer;

    int values[] = {
        10, 2, 43, 213, 342, 32, 111, 3322
    };

    for (const int value: values) {
        buffer.push(value);
        const int count = buffer.getCurrentSize();
        int *array = new int[count];
        buffer.values(array);
        printBuffer(array, count);
    }

    cout << "\n\n\n";

    for (int count = buffer.getCurrentSize(); count > 0; count = buffer.getCurrentSize()) {
        const int poppedValue = buffer.pop();
        cout << "Popped value: " << poppedValue << endl;
        int *array = new int[count];
        buffer.values(array);
        printBuffer(array, count - 1);
    }
}

void printBuffer(int *buffer, int size) {
    for (int count = 0; count < size; count++) {
        cout << buffer[count];
        if (count < size) cout << ", ";
        if (count + 1 == size)
            cout << endl;
    }
}
