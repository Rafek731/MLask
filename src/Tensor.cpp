#pragma once
#include<stdlib.h>
#include"mlask.h"
#include"Tensor.h"

using namespace mlask;

template <typename T>
Mat<T>::Mat(T* const data, int_t rows, int_t cols, bool copy = false) : rows(rows), 
                                                                        cols(cols), 
                                                                        data(copy ? new T [rows * cols]: data), 
                                                                        end_data(copy ? this->data + rows * cols : data + rows * cols) {
    if(copy) {
        int n_elements = rows * cols;
        for(int i = 0; i < n_elements; i++) {
            this->data[i] = data[i];
        }
    }
}


