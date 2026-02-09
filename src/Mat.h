#pragma once

namespace mlask{
    typedef float float_t;
    typedef int int_t;

    class Mat final{
    private:
        int_t rows;
        int_t cols;
        float_t ** const data;

    public:
        Mat(int_t rows, int_t cols);
        Mat(int_t rows, int_t cols, float_t** data);
        Mat(const Mat& mat);
        ~Mat();

        Mat operator+(const Mat& other);
        Mat& operator+=(const Mat& other);
        Mat operator+(const float_t scalar);
        Mat& operator+=(const float_t scalar);
        
        Mat operator-(const Mat& other);
        Mat& operator-=(const Mat& other);
        Mat operator-(const float_t scalar);
        Mat& operator-=(const float_t scalar);

        Mat operator*(const Mat& other);
        Mat& operator*=(const Mat& other);
        Mat operator*(const float_t scalar);
        Mat& operator*=(const float_t scalar);

        Mat operator/(const float_t scalar);
        Mat& operator/=(const float_t scalar);

        bool operator==(const Mat& other);
        bool operator!=(const Mat& other);

        bool tryGet(int_t row, int_t col, float_t& value);
        float_t& operator()(int_t row, int_t col);
        const float_t& operator()(int_t row, int_t col) const;
        float_t* operator[](int idx);

        Mat copy();

        void print();
    };

    void print_row(float_t *row, int_t row_len);
    
    float_t dot(const float_t *r1, const float_t *r2, int n);
}


