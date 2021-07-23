/*
    题目：
        多多君最近在研究某种数字组合：
        定义为：每个数字的十进制表示中(0~9)，每个数位各不相同且各个数位之和等于N。
        满足条件的数字可能很多，找到其中的最小值即可。
        多多君还有很多研究课题，于是多多君找到了你--未来的计算机科学家寻求帮助。
    输入描述:
        共一行，一个正整数N，如题意所示，表示组合中数字不同数位之和。（1 <= N <= 1,000）
    输出描述:
        共一行，一个整数，表示该组合中的最小值。
        如果组合中没有任何符合条件的数字，那么输出-1即可。
*/

#include <iostream>

int GetMinNum(const int N){
    if(N <= 9)
        return N;
    if(N >= 46)
        return -1;
    
    int result = 0;

    if(N <= 17)
        result = (N % 9) * 10 + 9;

    if(18 <= N && N <= 24)
        result = (N % 17) * 100 + 89;

    if(25 <= N && N <= 30)
        result = (N % 24) * 1000 + 789;

    if(31 <= N && N <= 35)
        result = (N % 30) * 10000 + 6789;

    if(36 <= N && N <= 39)
        result = (N % 35) * 100000 + 56789;

    if(40 <= N && N <= 42)
        result = (N % 39) * 1000000 + 456789;

    if(43 <= N && N <= 44)
        result = (N % 42) * 10000000 + 3456789;

    if(N == 45)
        result = 123456789;
    
    return result;
}

int main(){
    int N;
    std::cin >> N;
    std::cout << GetMinNum(N) << std::endl;
    return 0;
}