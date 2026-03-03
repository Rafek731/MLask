#pragma once
#include"mlask.h"
#include<assert.h>
using namespace mlask;

template <typename T> 
class Matrix {
    protected:
    int_t rows;
    int_t cols;
    T* data;
    T* end_data;

    public:
    Matrix(int_t rows, int_t cols); //ok
    Matrix(T** data, int_t rows, int_t cols);//ok
    Matrix(T* data, int_t rows, int_t cols, bool copy = false);//ok
    Matrix(T* data_start, T* end_data, int_t rows, int_t cols, bool copy = false); //ok
    Matrix(const Matrix& mat);
    ~Matrix();

    // Addidtion
    Matrix operator+(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);
    Matrix operator+(const T scalar) const;
    Matrix& operator+=(const T scalar);
    
    // Substraction
    Matrix operator-(const Matrixrix& other) const;
    Matrix& operator-=(const Matrix& other);
    Matrix operator-(const T scalar) const;
    Matrix& operator-=(const T scalar);

    // Multiplication
    Matrix operator*(const Matrix& other) const;
    Matrix& operator*=(const Matrix& other);
    Matrix operator*(const T scalar) const;
    Matrix& operator*=(const T scalar);

    // Division
    Matrix operator/(const T scalar) const;
    Matrix& operator/=(const T scalar);

    // Matrixching
    Matrix<bool> operator==(const Matrix& other) const;
    Matrix<bool> operator!=(const Matrix& other) const;

    static Matrix<bool> eq(const Matrix& Matrix1, const Matrix& Matrix2, float error);
    static Matrix<bool> neq(const Matrix& Matrix1, const Matrix& Matrix2, float error);

    T operator[](int row) const;
    T operator[](int_t row, int_t col) const;
    
    bool tryGet(int_t row, int_t col, T& value);

    Matrix copy();
    void print();

    // TODO: implement
    Matrix transpose();
    
};

template <typename T> 
class Vector : public Matrix {

};



/**
 * implementations
 */

template<typename T>
Matrix<T>::Matrix(int_t rows, int_t cols) {
    assert(rows > 0 && cols > 0);
    int n_elements = rows * cols;

    this->rows = rows;
    this->cols = cols;
    this->data = new T [n_elements];
    this->end_data = data + n_elements;
}


template<typename T>
Matrix<T>::Matrix(T** data, int_t rows, int_t cols) {
    assert(rows > 0 && cols > 0);
    int n_elements = rows*cols;

    this->rows = rows;
    this->cols = cols;
    this->data = new T [n_elements];
    this->end_data = data + n_elements;

    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            this->data[i * cols + j] = data[i][j]; 
        }
    }
}


template <typename T>
Matrix<T>::Matrix(T* data, int_t rows, int_t cols, bool copy = false) {
    assert(rows > 0 && cols > 0);
    int n_elements = rows * cols;

    this->rows = rows;
    this->cols = cols;

    if(copy) {
        this->data = new T [n_elements];
        this->end_data = this->data + n_elements;
        for(int i = 0; i < n_elements; i++) {
            this->data[i] = data[i];
        }
    }
    else {
        this->data = data;
        this->end_data= data + n_elements;
    }
}

template<typename T>
Matrix<T>::Matrix(T* data, T* end_data, int_t rows, int_t cols, bool copy = false) {
    assert(rows > 0 && cols > 0);
    int n_elements = rows * cols;
    this->rows = rows;
    this->cols = cols;

    if(copy) {
        this->data = new T [n_elements];
        this->end_data = this->data + n_elements;
        
        T* ptr = this->data;
        while(data < end_data){
            *(ptr++) = *(data++);
        }
    }
    else {
        this->data = data;
        this->end_data = data + n_elements;
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix& mat) {
    int n_elements = mat.rows * mat.cols;
    assert(rows > 0 && cols > 0);
    this->rows = mat.rows;
    this->cols = mat.cols;
    this->data = new T [n_elements];
    this->end_data = this->data + n_elements;
    for(int i=0; i < n_elements; i++) {
        this->data[i] = mat.data[i];
    }
}

