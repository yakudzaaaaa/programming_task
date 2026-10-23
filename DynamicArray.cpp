#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray(int size) {
    m_size = size;
    m_data = new int[size]();
}

DynamicArray::~DynamicArray() {
    delete[] m_data;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    m_size = other.m_size;
    m_data = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

void DynamicArray::print() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= m_size) {
        std::cout << "Error: index out of range" << std::endl;
        return;
    }
    if (value < -100 || value > 100) {
        std::cout << "Error: value must be from -100 to 100" << std::endl;
        return;
    }
    m_data[index] = value;
}

int DynamicArray::get(int index) const {
    if (index < 0 || index >= m_size) {
        std::cout << "Error: index out of range" << std::endl;
        return 0;
    }
    return m_data[index];
}

void DynamicArray::append(int value) {
    if (value < -100 || value > 100) {
        std::cout << "Error: value must be from -100 to 100" << std::endl;
        return;
    }
    int* newData = new int[m_size + 1];
    for (int i = 0; i < m_size; ++i) {
        newData[i] = m_data[i];
    }
    newData[m_size] = value;
    delete[] m_data;
    m_data = newData;
    m_size++;
}

void DynamicArray::add(const DynamicArray& other) {
    for (int i = 0; i < m_size; ++i) {
        int val2 = (i < other.m_size) ? other.m_data[i] : 0;
        m_data[i] = m_data[i] + val2;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (int i = 0; i < m_size; ++i) {
        int val2 = (i < other.m_size) ? other.m_data[i] : 0;
        m_data[i] = m_data[i] - val2;
    }
}