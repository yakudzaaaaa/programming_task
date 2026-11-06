#include <iostream>
#include <string>
#include "DynamicArray.h"

int main() {
    std::cout << std::boolalpha;

    // Задание 1: operator[]
    std::cout << " Task 1: operator[] " << std::endl;
    DynamicArray<int> arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    std::cout << "arr[1] = " << arr[1] << std::endl;
    std::cout << "arr = " << arr << std::endl;

    // Задание 1: out of range
    try {
        arr[5] = 1;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // Задание 2: == и !=
    std::cout << "\n Task 2: == and != " << std::endl;
    DynamicArray<int> b = arr;
    DynamicArray<int> c(3);
    c[0] = 1; c[1] = 2; c[2] = 3;
    std::cout << "arr == b: " << (arr == b) << std::endl;
    std::cout << "arr != c: " << (arr != c) << std::endl;

    // Задание 3: += и -= для массива
    std::cout << "\n Task 3: += and -= (array) " << std::endl;
    DynamicArray<int> x(3);
    x[0] = 10; x[1] = 20; x[2] = 30;
    DynamicArray<int> y(2);
    y[0] = 5; y[1] = 5;
    x += y;
    std::cout << "x += y: " << x << std::endl;
    x -= y;
    std::cout << "x -= y: " << x << std::endl;

    // Задание 3: += и -= для скаляра
    std::cout << "\n Task 3: += and -= (scalar) " << std::endl;
    DynamicArray<int> s(3);
    s[0] = 1; s[1] = 2; s[2] = 3;
    s += 10;
    std::cout << "s += 10: " << s << std::endl;
    s -= 5;
    std::cout << "s -= 5: " << s << std::endl;

    // Задание 4: читаем
    std::cout << "\n Task 4: range-for read " << std::endl;
    DynamicArray<std::string> str(2);
    str[0] = "Hello";
    str[1] = "World";
    for (const auto& item : str) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Задание 4: меняем
    std::cout << "\n Task 4: range-for modify " << std::endl;
    DynamicArray<int> mod(3);
    mod[0] = 1; mod[1] = 2; mod[2] = 3;
    for (auto& item : mod) {
        item += 1;
    }
    std::cout << "After modify: " << mod << std::endl;

    return 0;
}