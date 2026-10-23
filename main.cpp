#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << "Test 1: Create and output" << std::endl;
    DynamicArray arr1(3);
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);
    arr1.print();

    std::cout << "Test 2: Copy constructor" << std::endl;
    DynamicArray arr2 = arr1;
    arr2.print();

    std::cout << "Test 3: Adding to the end" << std::endl;
    arr1.append(40);
    arr1.print();

    std::cout << "Test 4: Array addition" << std::endl;
    DynamicArray arr3(2);
    arr3.set(0, 5);
    arr3.set(1, 5);
    arr1.add(arr3);
    arr1.print();

    return 0;
}