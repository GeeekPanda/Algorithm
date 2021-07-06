/*
    题目：
        输入两个整数，求这两个整数的和是多少。

        输入格式
            输入两个整数A,B，用空格隔开，0≤A,B≤108
        输出格式
            输出一个整数，表示这两个数的和
        样例输入
            3 4
        样例输出
            7
    思路：
        这题还需要思路？
*/



#include <iostream>

int Add(const int a, const int b){
    return a + b;
}

int main(){
    int A = 0;
    int B = 0;
    std::cin >> A >> B;
    std::cout << Add(A, B) << std::endl;
    return 0;
}