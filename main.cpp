#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << " Тест 1: invalid_argument " << std::endl;
    try {
        DynamicArray arr(3);
        arr.set(0, 150);
        std::cout << "Эта строка не напечатается" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймано исключение " << e.what() << std::endl;
    }

    std::cout << "\n Тест 2: out_of_range " << std::endl;
    try {
        DynamicArray arr(3);
        arr.get(10);
        std::cout << "Эта строка не напечатается" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Поймано исключение " << e.what() << std::endl;
    }

    std::cout << "\n Тест 3: bad_alloc " << std::endl;
    try {
        std::cout << "Попытка создать массив огромного размера..." << std::endl;
        DynamicArray hugeArray(2000000000);
        std::cout << "Эта строка не напечатается" << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cout << "Поймано исключение нехватка памяти" << std::endl;
    }

    std::cout << "\n Все тесты пройдены успешно! " << std::endl;
    return 0;
}