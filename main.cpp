/*
Copyright (c) 2023 Yige Zhang. All rights reserved.
*/

#include <iomanip>
#include <iostream>
#include <vector>

#include "Matrix.hpp"

int main() {
    // test constructor
    std::cout << "============ test constructor =================" << std::endl;
    auto matrix1 = Matrix<int>(2, 3);
    std::cout << "Matrix1: " << std::endl;
    matrix1.print();

    // test constructor with single value
    std::cout << "===== test constructor with single value ======" << std::endl;
    auto matrix2 = Matrix<float>(2, 3, 1.23);
    std::cout << "Matrix2: " << std::endl;
    matrix2.print();

    // test constructor with vector of vectors
    std::cout << "=== test constructor with vector of vectors ===" << std::endl;
    std::vector<std::vector<int>> vec{{1, 2, 3}, {4, 5, 6}};
    auto matrix3 = Matrix<int>(vec);
    std::cout << "Matrix3: " << std::endl;
    matrix3.print();

    // test copy constructor
    std::cout << "============= test copy constructor ===========" << std::endl;
    auto matrix4(matrix2);
    std::cout << "Matrix4 (Matrix2): " << std::endl;
    matrix4.print();

    auto matrix5 = matrix3;
    std::cout << "Matrix5 (=Matrix3): " << std::endl;
    matrix5.print();

    // test setter
    std::cout << "================ test setter ==================" << std::endl;
    matrix1.set(0, 0, 1);
    std::cout << "Matrix1: (set (0, 0) as 1)" << std::endl;
    matrix1.print();

    // test getter
    std::cout << "================ test getter ==================" << std::endl;

    std::cout << "Matrix1 at (0, 0) is: " << matrix1.get(0, 0) << std::endl;
    matrix1.print();

    // test == operator
    std::cout << "============== test == operator ===============" << std::endl;
    std::cout << "Matrix4 == Matrix2: " << std::boolalpha << (matrix4 == matrix2) << std::endl;
    std::cout << "Matrix5 == Matrix3: " << std::boolalpha << (matrix5 == matrix3) << std::endl;

    // test + operator
    std::cout << "=============== test + operator ===============" << std::endl;
    auto matrix6 = matrix3 + matrix5;
    std::cout << "Matrix6 (= matrix3 + matrix5): " << std::endl;
    matrix6.print();

    // test += operator
    std::cout << "============== test += operator ===============" << std::endl;
    matrix6 += matrix3;
    std::cout << "Matrix6 (+= matrix3): " << std::endl;
    matrix6.print();

    // test * operator
    std::cout << "============== test * operator ================" << std::endl;
    std::vector<std::vector<int>> vec1{{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> vec2{{1, 1}, {1, 1}, {1, 1}};

    auto m1 = Matrix<int>(vec1);
    std::cout << "m1: " << std::endl;
    m1.print();

    auto m2 = Matrix<int>(vec2);
    std::cout << "m2: " << std::endl;
    m2.print();

    auto m3 = m1 * m2;
    std::cout << "m3 (m1 * m2): " << std::endl;
    m3.print();

    // test *= operator
    std::cout << "============== test *= operator ===============" << std::endl;
    m3 *= m1;
    std::cout << "m3 (*= m1): " << std::endl;
    m3.print();

    return 0;
}
