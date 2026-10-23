#include <iostream>
#include <string>
#include "DynamicArray.h"

int main() {
    // Тест 1 invalid_argument
    std::cout << "=== Test 1: std::invalid_argument ===" << std::endl;
    try {
        DynamicArray<int> arr(3);
        arr.set(0, 150); // 150 вне -100..100
        std::cout << "This line will not be printed" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Тест 2 out_of_range
    std::cout << "\n=== Test 2: std::out_of_range ===" << std::endl;
    try {
        DynamicArray<int> arr(3);
        arr.get(10); // нет индекса 10
        std::cout << "This line will not be printed" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Тест 3 bad_alloc
    std::cout << "\n=== Test 3: std::bad_alloc ===" << std::endl;
    try {
        std::cout << "Trying to create a huge array..." << std::endl;
        DynamicArray<int> hugeArray(2000000000);
        std::cout << "This line will not be printed" << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cout << "Caught exception: not enough memory (bad_alloc)" << std::endl;
    }

    // Тест 4 целочисленный массив
    std::cout << "\n=== Test 4: operator<< with int ===" << std::endl;
    DynamicArray<int> arrInt(3);
    arrInt.set(0, 10);
    arrInt.set(1, 20);
    arrInt.set(2, 30);
    std::cout << "Integer array: " << arrInt << std::endl;

    // Тест 5 строковый массив
    std::cout << "\n=== Test 5: operator<< with string ===" << std::endl;
    DynamicArray<std::string> arrStr(2);
    arrStr.set(0, "Hello");
    arrStr.set(1, "World");
    std::cout << "String array: " << arrStr << std::endl;

    // Тест 6 дистанцция числовых массивов
    std::cout << "\n=== Test 6: distance (numeric) ===" << std::endl;
    try {
        DynamicArray<int> a(2);
        a.set(0, 0); a.set(1, 0);
        DynamicArray<int> b(2);
        b.set(0, 3); b.set(1, 4);
        std::cout << "Distance between [0,0] and [3,4]: " << a.distance(b) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Тест 7 дистанция нечисловой массив
    std::cout << "\n=== Test 7: distance (non-numeric, must fail) ===" << std::endl;
    try {
        DynamicArray<std::string> s1(1), s2(1);
        s1.set(0, "a");
        s2.set(0, "b");
        s1.distance(s2);
        std::cout << "This line will not be printed" << std::endl;
    } catch (const std::bad_typeid& e) {
        std::cout << "Caught bad_typeid: cannot calculate distance for non-numeric types" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Тест 8 дистанцция с разными размерами
    std::cout << "\n=== Test 8: distance (different sizes, must fail) ===" << std::endl;
    try {
        DynamicArray<int> x(2);
        DynamicArray<int> y(3);
        x.distance(y);
        std::cout << "This line will not be printed" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}