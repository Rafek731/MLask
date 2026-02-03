#include"Mat.cpp"
#include<stdio.h>
#include<assert.h>

using namespace mlask;

void test_addition(){ 
    Mat m1(3, 3);  
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m1[i][j] = 1.0;
        }
    }
    Mat m2(m1);
    Mat m3 = m1 + m2;
    assert(m3[0][0] == 2);
    assert(m1[0][0] == 1 && m2[0][0] == 1);
    m3+=m1;
    assert(m3[0][0] == 3);
    assert(m1[0][0] == 1 && m2[0][0] == 1);
    m3+=1;
    assert(m3[0][0] == 4);
    printf("Success\n");
}

void test_multiplication(){
    Mat m1(3, 2), m2(2,1);  
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            m1[i][j] = 2.0;
        }
    }
    
    m2[0][0] = 1;
    m2[1][0] = 2;
    m1.print();
    printf("\n");
    m2.print();
    printf("\n");
    Mat m3 = m1 * m2;
    m3.print();
    printf("\n");
    m3 *= 5;
    m3.print();
}   

void run_tests(){
    test_multiplication();
}

int main(){
    run_tests();
    return 0;
}