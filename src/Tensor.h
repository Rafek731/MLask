#pragma once
#include<assert.h>
#include"mlask.h"
#include<iostream>

using namespace mlask;

class Tensor {

};

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