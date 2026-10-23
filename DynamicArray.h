#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>
#include <iostream>
#include <cmath>
#include <type_traits>

// Класс шаблон
template <typename T>
class DynamicArray {
private:
    T* m_data;
    int m_size;

    // Проверка пределов для интов
    void checkIntegralBounds(const T& value) const {
        if constexpr (std::is_integral_v<T>) {
            if (static_cast<long long>(value) < -100 || static_cast<long long>(value) > 100) {
                throw std::invalid_argument("Value must be between -100 and 100 for integer types");
            }
        }
    }

public:
    // Конструктор
    DynamicArray(int size) {
        if (size < 0) {
            throw std::invalid_argument("Size cannot be negative");
        }
        m_size = size;
        m_data = new T[m_size]();
    }

    // Деструктор
    ~DynamicArray() {
        delete[] m_data;
    }

    // Конструктор копии
    DynamicArray(const DynamicArray& other) {
        m_size = other.m_size;
        m_data = new T[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    // Печать массива
    void print() const {
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Установить значчение по индексу
    void set(int index, const T& value) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of bounds (set)");
        }
        checkIntegralBounds(value);
        m_data[index] = value;
    }

    // Взять значение по индексу
    T get(int index) const {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of bounds (get)");
        }
        return m_data[index];
    }

    // Добавить в конец
    void append(const T& value) {
        checkIntegralBounds(value);
        T* newData = new T[m_size + 1];
        for (int i = 0; i < m_size; ++i) {
            newData[i] = m_data[i];
        }
        newData[m_size] = value;
        delete[] m_data;
        m_data = newData;
        m_size++;
    }

    // Сложить массивы
    void add(const DynamicArray& other) {
        for (int i = 0; i < m_size; ++i) {
            T val2 = (i < other.m_size) ? other.m_data[i] : T();
            m_data[i] = m_data[i] + val2;
        }
    }

    // Вычитание
    void subtract(const DynamicArray& other) {
        for (int i = 0; i < m_size; ++i) {
            T val2 = (i < other.m_size) ? other.m_data[i] : T();
            m_data[i] = m_data[i] - val2;
        }
    }

    // Евклидово расстояние
    double distance(const DynamicArray& other) const {
        if constexpr (!std::is_arithmetic_v<T>) {
            throw std::bad_typeid();
        }

        // размеры должны быть равны
        if (m_size != other.m_size) {
            throw std::invalid_argument("Array sizes must match for distance calculation");
        }

        double sum = 0.0;
        for (int i = 0; i < m_size; ++i) {
            double diff = static_cast<double>(m_data[i]) - static_cast<double>(other.m_data[i]);
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }

    // создание Фреда(Фред классный)
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& arr);
};

// реализация оператора
template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
    os << "[";
    for (int i = 0; i < arr.m_size; ++i) {
        os << arr.m_data[i];
        if (i < arr.m_size - 1) os << ", ";
    }
    os << "]";
    return os;
}

#endif