# Generic-Template-Matrix

#### A C++ generic template class for 2D matrix operations.

**Build and Run**

```
mkdir build
cmake -B ./build
cmake --build ./build
./build/Matrix

```

**Description**

An implementation of a generic class called Matrix which is a template class that can be instantiated with any data type. It has a number of member functions and operators to perform common matrix operations.

**Member functions and operators**

-   `Matrix(size_t row, size_t column)`: constructor that creates a matrix with specified number of rows and columns.

-   `Matrix(size_t row, size_t column, T value)`: constructor that creates a matrix with specified number of rows and columns and initializes all elements with a single value.

-   `Matrix(const std::vector<std::vector<T>> &values)`: constructor that creates a matrix from a 2D vector of values.
-   `Matrix(const Matrix &source)`: copy constructor to make a deep copy of a Matrix object.
-   `T &operator[](size_t index)`: overloads the square bracket operator to access 1D element of the matrix. Throws an exception if the index is invalid.
-   `bool operator==(const Matrix &other) const`: overloads the equality operator to check if two matrices are equal.
-   `Matrix &operator+=(const Matrix &other)`: overloads the add-and-assign operator to add two matrices and store the result in the current matrix. Throws an exception if the matrices are of incompatible sizes.
-   `Matrix &operator*=(const Matrix &other)`: overloads the multiply-and-assign operator to multiply two matrices and store the result in the current matrix. Throws an exception if the matrices are of incompatible sizes.
-   `Matrix &operator=(const Matrix &other)`: overloads the assignment operator to make a deep copy of a Matrix object.
-   `void set(size_t r, size_t c, const T &value)`: sets the value of an element in the matrix at position (r, c).
-   `T get(size_t r, size_t c) const`: returns the value of an element in the matrix at position (r, c).
-   `size_t row() const`: returns the number of rows in the matrix.
-   `size_t column() const`: returns the number of columns in the matrix.
-   `void print()`: prints the matrix to the console.
