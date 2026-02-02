#include"Mat.h"
#include<stdexcept>

namespace mlask{
    Mat::Mat(int_t rows, int_t cols) : rows(rows > 0 ? rows : 1), cols(cols), data(new float_t* [rows])
    {
        for(int i=0;i<rows;++i){
            data[i] = new float_t[cols];
        }
    }

    Mat::Mat(int_t rows, int_t cols, float_t** data) : rows(rows > 0 ? rows : 1), cols(cols), data(new float_t*[rows])
    {
        for(int i=0;i<rows;++i){
            this->data[i] = new float_t[cols];
            for(int j=0;j<cols;j++){
                this->data[i][j] = data[i][j];
            }
        }
    }

    Mat::Mat(const Mat& other) : rows(other.rows), cols(other.cols), data(new float_t* [rows])
    {
        for(int i=0;i<rows;++i){
            this->data[i] = new float_t[cols];
            for(int j=0;j<cols;j++){
                this->data[i][j] = other.data[i][j];
            }
        }
    }

    Mat::~Mat()
    {
        for(int i=0;i<rows;++i){
            delete[] data[i];
        }
        delete[] data;
    }

    Mat Mat::operator+(const Mat& other){
        if(this->rows != other.rows)    throw  std::invalid_argument("Cannot add Mats due to different sizes");
        if(this->cols != other.cols)    throw  std::invalid_argument("Cannot add Mats due to different sizes");

        Mat result(*this);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] += other.data[i][j];
            }
        }
        return result;
    }

    Mat& Mat::operator+=(const Mat& other){
        if(this->rows != other.rows)    throw  std::invalid_argument("Cannot add Mats due to different sizes");
        if(this->cols != other.cols)    throw  std::invalid_argument("Cannot add Mats due to different sizes");

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                this->data[i][j] += other.data[i][j];
            }
        }

        return *this;
    }

    Mat Mat::operator+(const float_t scalar){
        Mat result(*this);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] += scalar;
            }
        }
        return result;
    }

    Mat& Mat::operator+=(const float_t scalar){
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                this->data[i][j] += scalar;
            }
        }

        return *this;
    }
    
    Mat Mat::operator-(const Mat& other){
        if(this->rows != other.rows)    throw  std::invalid_argument("Cannot add Mats due to different sizes");
        if(this->cols != other.cols)    throw  std::invalid_argument("Cannot add Mats due to different sizes");

        Mat result(*this);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] -= other.data[i][j];
            }
        }
        return result;
    }

    Mat& Mat::operator-=(const Mat& other){
        if(this->rows != other.rows)    throw  std::invalid_argument("Cannot add Mats due to different sizes");
        if(this->cols != other.cols)    throw  std::invalid_argument("Cannot add Mats due to different sizes");

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                this->data[i][j] -= other.data[i][j];
            }
        }

        return *this;
    }

    Mat Mat::operator-(const float_t scalar){
        Mat result(*this);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] += scalar;
            }
        }
        return result;
    }

    Mat& Mat::operator-=(const float_t scalar){
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                this->data[i][j] -= scalar;
            }
        }

        return *this;
    }

    bool Mat::tryGet(int_t row, int_t col, float_t& value){
        if(row >= rows || row<0) return false;
        if(col >= cols || col<0) return false;
        value = data[row][col];
        return true;
    }

    const float_t& Mat::operator()(int_t row, int_t col) const{
        if(row >= rows || row<0) throw  std::invalid_argument("Cannot access outside of matrix");
        if(col >= cols || col<0) throw  std::invalid_argument("Cannot access outside of matrix");
        return data[row][col];
    }

    float_t& Mat::operator()(int_t row, int_t col){
        if(row >= rows || row<0) throw  std::invalid_argument("Cannot access outside of matrix");
        if(col >= cols || col<0) throw  std::invalid_argument("Cannot access outside of matrix");
        return data[row][col];
    }
}
