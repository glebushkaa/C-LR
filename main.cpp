#include "Stack.cpp"#include "Stack.h"#include <iostream>int main () {    Stack<int>* stack = new Stack<int> ();    std::cout << "Elements push started" << std::endl;    for (int i = 1; i <= 100; ++i) {        stack->push (i);        std::cout << "Pushed: " << i << ", Size: " << stack->getSize () << std::endl;    }    std::cout << std::endl;    std::cout << "Element peek started" << std::endl;    for (int i = 0; i < 3; i++) {        int value = stack->peek ();        std::cout << "Peeked: " << value << ", Size: " << stack->getSize () << std::endl;    }    std::cout << std::endl;    std::cout << "Elements pop started" << std::endl;    while (!stack->isEmpty ()) {        int value = stack->pop ();        std::cout << "Popped: " << value << ", Size: " << stack->getSize () << std::endl;    }    delete stack;    return 0;}