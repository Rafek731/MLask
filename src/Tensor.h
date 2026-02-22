#include"mlask.h"

using namespace mlask;

class Tensor {

};


template <typename T> class Mat {
protected:
    int_t rows;
    int_t cols;
    T** const data;

public:
    Mat(int_t rows, int_t cols);
    Mat(int_t rows, int_t cols, T** data);
    Mat(const Mat& mat);
    ~Mat();

    // Addidtion
    Mat operator+(const Mat& other);
    Mat& operator+=(const Mat& other);
    Mat operator+(const T scalar);
    Mat& operator+=(const T scalar);
    
    // Substraction
    Mat operator-(const Mat& other);
    Mat& operator-=(const Mat& other);
    Mat operator-(const T scalar);
    Mat& operator-=(const T scalar);

    // Multiplication
    Mat operator*(const Mat& other);
    Mat& operator*=(const Mat& other);
    Mat operator*(const T scalar);
    Mat& operator*=(const T scalar);

    // Division
    Mat operator/(const T scalar);
    Mat& operator/=(const T scalar);

    // Matching
    bool operator==(const Mat& other);
    bool operator!=(const Mat& other);

    
    const T& operator()(int_t row, int_t col) const;
    T& operator()(int_t row, int_t col);
    T* operator[](int row);
    T operator[](int_t row, int_t col);
    
    bool tryGet(int_t row, int_t col, T& value);

    Mat copy();
    void print();

    // TODO: implement
    Mat transpose();
    

};


template <typename T> class sqMat : Mat<T>{
public:
    Mat inverse();
    T det(); 
    Mat adj();
    Mat cross(int_t row, int_t col);
    int rank();
};


/**
 * Vector class
 * if length > 0 -> column vector
 * if length < 0 -> row vector
 * 
 * lenghth is number of elements in the vector
 * size is declared space (power of 2) for the vector for faster computation (fast multiplication with matricies algorithms)
 * e.g. if you want to have a vector of 10 floats the space the vector occupies would be as big as 16 floats but you'll have access to only 10 floats
 * ^^^ to consider
 */
template <typename T> class Vector {
    T* const v;
    int length;

    public:
    Vector(int n);
    Vector();
    ~Vector();
    
    // addidion
    Vector operator+(Vector other);
    Vector operator+(T scalar);
    Vector& operator+=(Vector other);
    Vector& operator+=(T scalar);
    
    // substraction
    Vector operator-(Vector other);
    Vector operator-(T scalar);
    Vector& operator-=(Vector other);
    Vector& operator-=(T scalar);
    
    // multiplication
    Vector operator*(T scalar);
    Vector operator*(Vector other);
    Vector& operator*=(Vector other);
    Vector& operator*=(T scalar);
    
    // divistion
    Vector operator/(T scalar);
    Vector& operator/=(T scalar);
    
    // dot operation
    T operator%(Vector& other) const;
    T dot(Vector& other) const;
    
    
    // cross product
    T operator&(Vector& other);
    T cross(Vector& other) const;

    
    T operator[](int n) const;

    size_t size() const;
    unsigned int length() const;
    void transpose();
    bool set(int_t idx, T value);
};