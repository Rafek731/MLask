namespace mlask{
    template<typename float_t, typename int_t>
    class Mat final{
    private:
        int_t rows;
        int_t cols;
        float_t *t;

    public:
        Mat(int_t rows, int_t cols);
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
        Mat operator*(const float_t scalar);
        Mat& operator*=(const float_t scalar);

        Mat operator/(const float_t scalar);
        Mat& operator/=(const float_t scalar);

        bool operator==(const Mat& other);
        bool operator!=(const Mat& other);

        void print();

    };
}


