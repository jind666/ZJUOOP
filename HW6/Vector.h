#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <class T>
class Vector {
public:
    Vector() : m_pElements(nullptr), m_nSize(0), m_nCapacity(0) {}

    Vector(int size) : m_pElements(size > 0 ? new T[size] : nullptr), m_nSize(0), m_nCapacity(size) {}

    Vector(const Vector& r) : m_pElements(new T[r.m_nCapacity]), m_nSize(r.m_nSize), m_nCapacity(r.m_nCapacity) {
        for (int i = 0; i < m_nSize; ++i) {
            m_pElements[i] = r.m_pElements[i];
        }
    }

    ~Vector() {
        delete[] m_pElements;
    }

    T& operator[](int index) {
        return m_pElements[index];
    }

    T& at(int index) {
        if (index < 0 || index >= m_nSize) {
            throw std::out_of_range("Vector::at");
        }
        return m_pElements[index];
    }

    int size() const {
        return m_nSize;
    }

    void push_back(const T& x) {
        if (m_nSize == m_nCapacity) {
            inflate();
        }
        m_pElements[m_nSize++] = x;
    }

    void clear() {
        m_nSize = 0;
    }

    bool empty() const {
        return m_nSize == 0;
    }

private:
    void inflate() {
        int newCapacity = m_nCapacity == 0 ? 1 : m_nCapacity * 2; // 扩容，在我的实现中扩容将容量扩充为原来的两倍。
        T* newElements = new T[newCapacity];
        for (int i = 0; i < m_nSize; i++) {
            newElements[i] = m_pElements[i];
        }
        delete[] m_pElements;
        m_pElements = newElements;
        m_nCapacity = newCapacity;
    }

    T* m_pElements;
    int m_nSize;
    int m_nCapacity;
};

#endif // VECTOR_H
