#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>
#include <iostream>
#include <cmath>
#include <type_traits>

template <typename T>
class DynamicArray {
private:
    T* m_data;
    int m_size;

    // проверка грааницц для интов
    void checkIntegralBounds(const T& value) const {
        if constexpr (std::is_integral_v<T>) {
            if (static_cast<long long>(value) < -100 || static_cast<long long>(value) > 100) {
                throw std::invalid_argument("Value must be between -100 and 100");
            }
        }
    }

public:
    class Proxy {
    private:
        DynamicArray* m_arr;
        int m_index;
    public:
        Proxy(DynamicArray* arr, int index) : m_arr(arr), m_index(index) {}

        Proxy& operator=(const T& value) {
            m_arr->set(m_index, value);
            return *this;
        }

        operator T&() const {
            return m_arr->m_data[m_index];
        }
    };

    DynamicArray(int size) {
        if (size < 0) {
            throw std::invalid_argument("Size cannot be negative");
        }
        m_size = size;
        m_data = new T[m_size]();
    }

    ~DynamicArray() {
        delete[] m_data;
    }

    DynamicArray(const DynamicArray& other) {
        m_size = other.m_size;
        m_data = new T[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    void print() const {
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of bounds (set)");
        }
        checkIntegralBounds(value);
        m_data[index] = value;
    }

    T get(int index) const {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of bounds (get)");
        }
        return m_data[index];
    }

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

    void add(const DynamicArray& other) {
        for (int i = 0; i < m_size; ++i) {
            T val2 = (i < other.m_size) ? other.m_data[i] : T();
            m_data[i] = m_data[i] + val2;
        }
    }

    void subtract(const DynamicArray& other) {
        for (int i = 0; i < m_size; ++i) {
            T val2 = (i < other.m_size) ? other.m_data[i] : T();
            m_data[i] = m_data[i] - val2;
        }
    }

    // Задание 1: arr[i]
    Proxy operator[](int index) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of bounds (operator[])");
        }
        return Proxy(this, index);
    }

    // Задание 2: == и !=
    bool operator==(const DynamicArray& other) const {
        if (m_size != other.m_size) return false;
        for (int i = 0; i < m_size; ++i) {
            if (m_data[i] != other.m_data[i]) return false;
        }
        return true;
    }

    bool operator!=(const DynamicArray& other) const {
        return !(*this == other);
    }

    // Задание 3: += и -= для массивов
    DynamicArray& operator+=(const DynamicArray& other) {
        add(other);
        return *this;
    }

    DynamicArray& operator-=(const DynamicArray& other) {
        subtract(other);
        return *this;
    }

    // Задание 3: += и -= для скаляров
    DynamicArray& operator+=(const T& value) {
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = m_data[i] + value;
        }
        return *this;
    }

    DynamicArray& operator-=(const T& value) {
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = m_data[i] - value;
        }
        return *this;
    }

    // Задание 3 расстояние
    double distance(const DynamicArray& other) const {
        if constexpr (!std::is_arithmetic_v<T>) {
            throw std::bad_typeid();
        }
        if (m_size != other.m_size) {
            throw std::invalid_argument("Sizes must match");
        }
        double sum = 0.0;
        for (int i = 0; i < m_size; ++i) {
            double diff = static_cast<double>(m_data[i]) - static_cast<double>(other.m_data[i]);
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }

    // Задание 4: итераторы
    T* begin() { return m_data; }
    T* end() { return m_data + m_size; }
    const T* begin() const { return m_data; }
    const T* end() const { return m_data + m_size; }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& arr);
};

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