#include <iostream>

#include "Matrix.hpp"

Matrix<int> test_constructor(const int row, const int column) { return Matrix<int>(row, column); }

Matrix<float> test_constructor_single_value(const int row, const int column, const float value) {
    return Matrix<float>(row, column, value);
}

Matrix<int> test_setter(const int row, const int column) {
    Matrix<int> matrix(row, column);
    int i = 0;
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            matrix.set(r, c, i);
            i++;
        }
    }
    return matrix;
}

Matrix<int> test_addition_operator(Matrix<int>& m1, Matrix<int>& m2) {
    return Matrix<int>(m1 + m2);
}

int main() {
    // test constructor
    Matrix<int> matrix1 = test_constructor(2, 3);
    std::cout << "Matrix1: " << std::endl;
    matrix1.print();

    // test constructor with single value
    Matrix<float> matrix2 = test_constructor_single_value(2, 3, 1.23);
    std::cout << "Matrix2: " << std::endl;
    matrix2.print();

    // test setter
    Matrix<int> matrix3 = test_setter(3, 3);
    std::cout << "Matrix3: " << std::endl;
    matrix3.print();

    // test copy constructor
    auto matrix4(matrix2);
    std::cout << "Matrix4 (Matrix2): " << std::endl;
    matrix4.print();

    auto matrix5 = matrix3;
    std::cout << "Matrix5 (=Matrix3): " << std::endl;
    matrix5.print();

    // test + operator
    auto matrix6 = matrix3 + matrix5;
    std::cout << "Matrix6 (= matrix3 + matrix5): " << std::endl;
    matrix6.print();

    // test += operator
    matrix6 += matrix3;
    std::cout << "Matrix6 (+= matrix3): " << std::endl;
    matrix6.print();

    /*

    // +
    Matrix<int> matrix3 = matrix + matrix2;
    std::cout << "matrix + matrix2 " << std::endl;
    matrix3.print();

    // *
    Matrix<int> matrix4(3, 3);
    i = 0;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            i++;
            matrix4.assign(r, c, i);
        }
    }
    std::cout << "matrix " << std::endl;
    matrix.print();
    std::cout << "matrix4 " << std::endl;
    matrix4.print();
    Matrix<int> matrix5 = matrix * matrix4;
    std::cout << "matrix4 * matrix" << std::endl;
    matrix5.print();

    Matrix<int> matrix6(1, 2, 2);
    Matrix<int> matrix7(0, 2, 2);
    matrix7.print();
    matrix7 = matrix6;
    matrix7.print();

    */
    return 0;
}
