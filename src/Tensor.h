#pragma once
#include"mlask.h"

using namespace mlask;

template <typename T> 
class Mat {
    protected:
    int_t rows;
    int_t cols;
    T* const data;

    public:
    Mat(int_t rows, int_t cols);
    Mat(T** data, int_t rows, int_t cols);
    Mat(T* data, int_t rows, int_t cols);
    Mat(const Mat& mat);
    ~Mat();

    // Addidtion
    Mat operator+(const Mat& other) const;
    Mat& operator+=(const Mat& other);
    Mat operator+(const T scalar) const;
    Mat& operator+=(const T scalar);
    
    // Substraction
    Mat operator-(const Mat& other) const;
    Mat& operator-=(const Mat& other);
    Mat operator-(const T scalar) const;
    Mat& operator-=(const T scalar);

    // Multiplication
    Mat operator*(const Mat& other) const;
    Mat& operator*=(const Mat& other);
    Mat operator*(const T scalar) const;
    Mat& operator*=(const T scalar);

    // Division
    Mat operator/(const T scalar) const;
    Mat& operator/=(const T scalar);

    // Matching
    Mat<bool> operator==(const Mat& other) const;
    Mat<bool> operator!=(const Mat& other) const;

    static Mat<bool> eq(const Mat& mat1, const Mat& mat2, float error);
    static Mat<bool> neq(const Mat& mat1, const Mat& mat2, float error);

    T operator[](int row) const;
    T operator[](int_t row, int_t col) const;
    
    bool tryGet(int_t row, int_t col, T& value);

    Mat copy();
    void print();

    // TODO: implement
    Mat transpose();
    
};

template <typename T> 
class Vector : public Mat {

};