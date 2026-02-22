#include"declarations.h"
#include"Tensor.h"

using namespace mlask;
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
    T* v;
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
    
    T operator[](int n);

    size_t size();
    T dot(Vector other);
    unsigned int length();
    void transpose();

};