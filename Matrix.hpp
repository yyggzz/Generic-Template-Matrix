/*
Copyright (c) 2023 Yige Zhang. All rights reserved.
*/

#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

template <typename T>
class Matrix {
   public:
    Matrix(size_t row, size_t column);                  // constructor
    Matrix(size_t row, size_t column, T value);         // constructor with single value
    Matrix(const std::vector<std::vector<T>> &values);  // constructor with vector of vectors
    Matrix(const Matrix &source);                       // copy constructor;

    T &operator[](size_t index);                 // overloading [], access 1D element
    bool operator==(const Matrix &other) const;  // overloading == operator
    Matrix &operator+=(const Matrix &other);     // overloading +=
    Matrix &operator*=(const Matrix &other);     // overloading *=
    Matrix &operator=(const Matrix &other);      // overloading = assignment operator

    void set(size_t r, size_t c, const T &value);  // setter of element
    T get(size_t r, size_t c) const;               // getter of element

    size_t row() const { return m_row; };        // getter of no. of rows
    size_t column() const { return m_column; };  // getter of no. of columns

    void print();  // print to console

   private:
    std::unique_ptr<T[]> m_matrix;
    size_t m_row;
    size_t m_column;
};

// constructor
template <typename T>
Matrix<T>::Matrix(size_t row, size_t column) {
    std::cout << "Constructor by row size and column size." << std::endl;
    m_matrix = std::make_unique<T[]>(row * column);
    this->m_row = row;
    this->m_column = column;
}

// constructor with single value
template <typename T>
Matrix<T>::Matrix(size_t row, size_t column, T value) : Matrix(row, column) {
    std::cout << "Constructor with single value by row size and column size." << std::endl;
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            set(r, c, value);
        }
    }
}

// constructor with vector of vectors of values
template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> &values)
    : Matrix(values.size(), values[0].size()) {
    std::cout << "Constructor with vector of vectors." << std::endl;
    for (int r = 0; r < row(); r++) {
        for (int c = 0; c < column(); c++) {
            set(r, c, values[r][c]);
        }
    }
}

// copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix &source) : Matrix(source.row(), source.column()) {
    std::cout << "Overloading copy constructor called." << std::endl;
    for (int r = 0; r < source.row(); r++) {
        for (int c = 0; c < source.column(); c++) {
            set(r, c, source.get(r, c));
        }
    }
}

// overloading [], access 1D element
template <typename T>
T &Matrix<T>::operator[](size_t index) {
    if (index >= m_row * m_column) {
        throw std::invalid_argument("Invalid index!");
    }
    return m_matrix[index];
}

// overloading == operator
template <typename T>
bool Matrix<T>::operator==(const Matrix &other) const {
    for (int r = 0; r < other.row(); r++) {
        for (int c = 0; c < other.column(); c++) {
            if (other.get(r, c) != get(r, c)) return false;
        }
    }
    return true;
}

// overloading +=
template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix &other) {
    if (other.row() != m_row || other.column() != m_column)
        throw std::invalid_argument("Incompatible matrix size for +");

    for (int r = 0; r < m_row; r++) {
        for (int c = 0; c < m_column; c++) {
            set(r, c, get(r, c) + other.get(r, c));
        }
    }
    std::cout << "Overloading += operator" << std::endl;
    return *this;
}

// overloading +
template <typename T>
Matrix<T> operator+(const Matrix<T> &first, const Matrix<T> &second) {
    Matrix<T> tmp = first;
    tmp += second;
    std::cout << "Overloading + operator" << std::endl;
    return tmp;
}

// overloading *=
template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &other) {
    std::cout << "Overloading *= operator" << std::endl;
    if (column() != other.row()) throw std::invalid_argument("Incompatible matrix size for *=");
    Matrix<T> copy = *this;
    m_column = other.column();
    *this = copy * other;
    return *this;
}

// overloading *
template <typename T>
Matrix<T> operator*(const Matrix<T> &first, const Matrix<T> &second) {
    std::cout << "Overloading * operator" << std::endl;
    const int row = first.row();
    const int column = second.column();
    const int n = first.column();
    if (second.row() != n) throw std::invalid_argument("Incompatible matrix size for *");

    Matrix<T> result(row, column);
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            T tmp = 0;
            for (int i = 0; i < n; i++) {
                tmp += first.get(r, i) * second.get(i, c);
            }
            result.set(r, c, tmp);
        }
    }

    return result;
}

// overloading = assignment operator
template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &source) {
    if (source.row() != m_row || source.column() != m_column)
        throw std::invalid_argument("Incompatible matrix size for =");

    for (int r = 0; r < source.row(); r++) {
        for (int c = 0; c < source.column(); c++) {
            set(r, c, source.get(r, c));
        }
    }
    std::cout << "Overloading = operator" << std::endl;
    return *this;
}

// setter of element
template <typename T>
void Matrix<T>::set(size_t r, size_t c, const T &value) {
    m_matrix[m_column * r + c] = value;
}

// getter of element
template <typename T>
T Matrix<T>::get(size_t r, size_t c) const {
    return m_matrix[m_column * r + c];
}

// print to console
template <typename T>
void Matrix<T>::print() {
    for (int r = 0; r < m_row; r++) {
        for (int c = 0; c < m_column; c++) {
            std::cout << get(r, c) << " ";
        }
        std::cout << std::endl;
    }
}
