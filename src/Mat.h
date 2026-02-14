#pragma once
#include "declarations.h"
namespace mlask {
    class Mat final {
    private:
        int_t rows;
        int_t cols;
        float_t ** const data;

    public:
        Mat(int_t rows, int_t cols);
        Mat(int_t rows, int_t cols, float_t** data);
        Mat(const Mat& mat);
        ~Mat();

        // Addidtion
        Mat operator+(const Mat& other);
        Mat& operator+=(const Mat& other);
        Mat operator+(const float_t scalar);
        Mat& operator+=(const float_t scalar);
        
        // Substraction
        Mat operator-(const Mat& other);
        Mat& operator-=(const Mat& other);
        Mat operator-(const float_t scalar);
        Mat& operator-=(const float_t scalar);

        // Multiplication
        Mat operator*(const Mat& other);
        Mat& operator*=(const Mat& other);
        Mat operator*(const float_t scalar);
        Mat& operator*=(const float_t scalar);

        // Division
        Mat operator/(const float_t scalar);
        Mat& operator/=(const float_t scalar);

        // Matching
        bool operator==(const Mat& other);
        bool operator!=(const Mat& other);

        
        const float_t& operator()(int_t row, int_t col) const;
        float_t& operator()(int_t row, int_t col);
        float_t* operator[](int idx);
        
        bool tryGet(int_t row, int_t col, float_t& value);

        Mat copy();
        void print();

        // TODO: implement
        Mat transpose();
        Mat inverse(); // Subclass for square matrix?
        float_t det(); // Subclass for square matrix?
        Mat adj();     // Subclass for square matrix?
        Mat cross(int_t row, int_t col);
        int rank();

    };

    void print_row(float_t *row, int_t row_len);
    
    float_t dot(const float_t *r1, const float_t *r2, int n);
}


