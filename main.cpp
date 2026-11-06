#include <iostream>
#include <string>
#include <utility>
#include "DynamicArray.h"

// для lvalue - конструктор копирования, для rvalue — конструктор перемещения
void takeByValue(DynamicArray<int> arr) {
    std::cout << "  inside function: " << arr << std::endl;
}

int main() {
    
    // Задача 1 оператор присваивания
    std::cout << "\n Task 1: copy assignment " << std::endl;
    DynamicArray<int> x(2);
    x.set(0, 10); x.set(1, 20);
    DynamicArray<int> y(5);
    y = x;
    std::cout << "  y = x: " << y << std::endl;
    y = y; // self-assignment guard
    std::cout << "  y = y (self): " << y << std::endl;

    // Задание 2 + Задание 3 мув конструктор и оператор
    std::cout << "\n Task 2/3: move assignment " << std::endl;
    DynamicArray<int> z(2);
    z.set(0, 7); z.set(1, 8);
    DynamicArray<int> w(1);
    w = std::move(z);
    std::cout << "  w after move-assign: " << w << std::endl;
    std::cout << "  z after move-assign: " << z << std::endl;
    
    // Задача 4 дороге копирование
    std::cout << " Pass by value: copy " << std::endl;
    DynamicArray<int> src(3);
    src.set(0, 1); src.set(1, 2); src.set(2, 3);
    takeByValue(src);
    std::cout << "  src after copy-pass: " << src << std::endl;

    // Задача 4 перенос указателя
    std::cout << "\n Pass by value: move " << std::endl;
    takeByValue(std::move(src));
    std::cout << "  src after move-pass: " << src << std::endl;


    return 0;
}