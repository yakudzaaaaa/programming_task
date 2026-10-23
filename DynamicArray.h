#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private:
    int* m_data;
    int m_size;

public:
    DynamicArray(int size);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);

    void print() const;
    void set(int index, int value);
    int get(int index) const;
    void append(int value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif