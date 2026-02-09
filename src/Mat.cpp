#include"Mat.h"
#include<stdexcept>
#include<stdio.h>

namespace mlask{
    Mat::Mat(int_t rows, int_t cols) : rows(rows > 0 ? rows : 1), cols(cols > 0 ? cols : 1), data(new float_t* [rows]){
        for(int i=0;i<rows;++i){
            data[i] = new float_t[cols];
        }
    }

    Mat::Mat(int_t rows, int_t cols, float_t** data) : rows(rows > 0 ? rows : 1), cols(cols > 0 ? cols : 1), data(new float_t*[rows]){
        for(int i=0;i<rows;++i){
            this->data[i] = new float_t[cols];
            for(int j=0;j<cols;j++){
                this->data[i][j] = data[i][j];
            }
        }
    }

    Mat::Mat(const Mat& other) : rows(other.rows), cols(other.cols), data(new float_t* [rows]){
        for(int i=0;i<rows;++i){
            this->data[i] = new float_t[cols];
            for(int j=0;j<cols;j++){
                this->data[i][j] = other.data[i][j];
            }
        }
    }

    Mat::~Mat(){
        for(int i=0;i<rows;++i){
            delete[] data[i];
        }
        delete[] data;
    }

    Mat Mat::operator+(const Mat& other){
        if(this->rows != other.rows || this->cols != other.cols)    throw  std::invalid_argument("Cannot add Mats due to different sizes");

        Mat result(*this);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] += other.data[i][j];
            }
        }
        return result;
    }

    Mat& Mat::operator+=(const Mat& other){
        if(this->rows != other.rows || this->cols != other.cols)    throw  std::invalid_argument("Cannot add Mats due to different sizes");

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
        if(this->rows != other.rows || this->cols != other.cols) throw  std::invalid_argument("Cannot add Mats due to different sizes");

        Mat result(*this);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] -= other.data[i][j];
            }
        }
        return result;
    }

    Mat& Mat::operator-=(const Mat& other){
        if(this->rows != other.rows || this->cols != other.cols)    throw  std::invalid_argument("Cannot add Mats due to different sizes");

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
        if(col >= cols || col < 0 || row >= rows || row < 0) return false;
        value = data[row][col];
        return true;
    }

    const float_t& Mat::operator()(int_t row, int_t col) const{
        if(col >= cols || col<0 || row >= rows || row<0) throw  std::invalid_argument("Cannot access outside of matrix");
        return data[row][col];
    }

    float_t& Mat::operator()(int_t row, int_t col){
        if(col >= cols || col<0 || row >= rows || row<0) throw  std::invalid_argument("Cannot access outside of matrix");
        return data[row][col];
    }

    Mat& Mat::operator*=(const float_t scalar){
        float_t **row = data;                               // get first row
        float_t **last_row = data + rows;             // get last row
        while(row < last_row){                              // iterate through all rows
            float_t *col = *row, *last_col = *row + cols;   // get first and last element of the row
            while(col < last_col)                           // iterate through whole row
                *(col++) *= scalar;                         // jump to next element
            row++;                                          // jump to next row
        }

        return *this;
    }

    Mat Mat::operator*(const float_t scalar){
        Mat result(*this);
        result *= scalar;
        return result;
    }

    Mat& Mat::operator/=(const float_t scalar){
        float_t **row = data;                               // get first row
        float_t **last_row = data + rows;             // get last row
        while(row < last_row){                              // iterate through all rows
            float_t *col = *row, *last_col = *row + cols;   // get first and last element of the row
            while(col < last_col)                           // iterate through whole row
                *(col++) /= scalar;                         // jump to next element  
            row++;                                          // jump to next row
        }

        return *this;
    }

    Mat Mat::operator/(const float_t scalar){
        Mat result(*this);
        result /= scalar;
        return result;
    }
    

    Mat Mat::copy(){
        Mat result(*this);
        return result;
    }

    void print_row(float_t *row, int_t row_len){
        if(row_len > 15){
            for(int i=0; i < 5; i++) printf("%.3f ", row[i]);
            printf("... ");
            for(int i=row_len-5; i < row_len; i++) printf("%.3f ", row[i]);
        }
        else{
            for(int i=0; i< row_len; i++)
                printf("%.3f ", row[i]);

        }
        printf("\n");
    }

    void Mat::print(){
        if(rows > 15){
            for(int i=0; i < 5; i++) print_row(data[i], rows);
            printf("... ");
            for(int i=rows-5; i < rows; i++) print_row(data[i], rows);
        }
        else{
            for(int i=0; i< rows; i++)
                print_row(data[i], cols);

        }
    }
    
    inline float_t* Mat::operator[](int idx){
        if(idx < 0 || idx >= rows) throw std::invalid_argument("Index out of bound");
        return data[idx];
    }

    Mat Mat::operator*(const Mat& other){
        if(this->cols != other.rows) throw  std::invalid_argument("Cannot multiply Mats due to different inner sizes");
        Mat result(this->rows, other.cols);
        float_t *tmp;
        for(int i=0; i < result.rows; i++){
            for(int j = 0; j < result.cols; j++){
                tmp = result[i] + j;
                for(int k=0; k < this->cols; k++){
                    *tmp += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

}
