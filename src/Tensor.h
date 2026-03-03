#pragma once
#include<assert.h>
#include"mlask.h"
#include<iostream>

using namespace mlask;

class Tensor {

};


template <typename T> class Matrix {
protected:
    int_t rows;
    int_t cols;
    T* data;

public:
    Matrix(int_t rows, int_t cols);
    Matrix(int_t rows, int_t cols, T* data);
    Matrix(const Matrix& mat);
    //~Matrix()

    // Addidtion
    Matrix operator+(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix operator+(const T scalar);
    Matrix& operator+=(const T scalar);
    
    // Substraction
    Matrix operator-(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator-(const T scalar);
    Matrix& operator-=(const T scalar);

    // Multiplication
    Matrix operator*(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix operator*(const T scalar);
    Matrix& operator*=(const T scalar);

    // Division
    Matrix operator/(const T scalar);
    Matrix& operator/=(const T scalar);

    // Matching
    Matrix<bool> operator==(const Matrix& other, T error);
    Matrix<bool> operator!=(const Matrix& other, T error);

    const T& operator()(int_t rows, int_t cols ) const;
    T& operator()(int_t rows, int_t cols);
    T* operator[](int rows);
    //T operator[](int_t rows, int_t cols);
    
    bool tryGet(int_t row, int_t col, T& value);

    Matrix copy();
    void print();

    // TODO: implement
    Matrix transpose();
    

};

//Addition
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other){
    //assert correct dimensions
    assert(rows == other.rows);
    assert(cols == other.cols);
    
    T* new_data = new T[rows * cols];
    T* cell = data;
    T* other_cell = other.data;

    for(size_t i=0;i<rows*cols;cell++, new_data++, i++){
        *new_data = *cell + *other_cell;
    }

    return new Matrix<T>(rows, cols, new_data);
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other){
    //assert correct dimensions
    assert(rows == other.rows);
    assert(cols == other.cols);
    
    T* cell = data;
    T* other_cell = other.data;

    for(size_t i=0;i<rows*cols;cell++, i++){
        *cell = *cell + *other_cell;
    }

    return *this;
}

//Substraction
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other){
    //assert correct dimensions
    assert(rows == other.rows);
    assert(cols == other.cols);
    
    T* new_data = new T[rows * cols];
    T* cell = data;
    T* other_cell = other.data;

    for(size_t i=0;i<rows*cols;cell++, new_data++, i++){
        *new_data = *cell - *other_cell;
    }

    return new Matrix<T>(rows, cols, new_data);
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other){
    //assert correct dimensions
    assert(rows == other.rows);
    assert(cols == other.cols);
    
    T* cell = data;
    T* other_cell = other.data;

    for(size_t i=0;i<rows*cols;cell++, i++){
        *cell = *cell - *other_cell;
    }

    return *this;
}

template<typename T>
void Matrix<T>::print(){
    T* cell = data;
    for(size_t i=0;i<rows*cols;i++, cell++){
        std::cout<<*cell<<" ";
        if(i%cols == 0){
            std::cout<<std::endl;
        }
    }
}

    // Matching
template<typename T>
Matrix<bool> Matrix<T>::operator==(const Matrix& other,T error){
    if(rows!=other.rows){
        return false;
    }
    if(cols!=other.cols){
        return false;
    }

    T* this_cell = this.data;
    T* other_cell = other.data;

    bool* bool_matrix = new bool[rows*cols];
    bool* bool_cell
    for (size_t i=0;i<rows*cols;i++, this_cell++, other_cell++, bool_cell++){
        *bool_cell = (abs(this_cell-other_cell) <= error);
    }
    return new Matrix(rows, cols, bool_matrix);
}

template<typename T>
bool Matrix<T>::operator!=(const Matrix& other){

}

template<typename T>
const T& Matrix<T>::operator()(int_t row, int_t col) const{

}
template<typename T>
T& Matrix<T>::operator()(int_t row, int_t col){

}
template<typename T>
T* Matrix<T>::operator[](int row){

}
//T operator[](int_t row, int_t col);

bool tryGet(int_t row, int_t col, T& value);

Matrix copy();