/*
    题目：
        多多君最近在研究字符串之间的变换，可以对字符串进行若干次变换操作:
            交换任意两个相邻的字符，代价为0。
            将任意一个字符a修改成字符b，代价为 |a - b|（绝对值）。
        现在有两个长度相同的字符串X和Y，多多君想知道，如果要将X和Y变成两个一样的字符串，需要的最少的代价之和是多少。
    输入描述:
        共三行，第一行，一个整数N，表示字符串的长度。（1 <= N <= 2,000）
        接下来两行，每行分别是一个字符串，表示字符串X和Y。（字符串中仅包含小写字母）
    输出描述:
        共一行，一个整数，表示将X和Y变换成一样的字符串需要的最小的总代价。
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

int GetMinCost(const int N, std::string& X, std::string& Y){
    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());
    int result = 0;
    for(int i = 0; i < N; ++i){
        if(X[i] != Y[i])
            result += abs(X[i] - Y[i]);
    }
    return result;
}

int main(){
    int N;
    std::cin >> N;

    std::cin.get();

    std::string X;
    getline(std::cin, X);

    std::string Y;
    getline(std::cin, Y);

    std::cout << GetMinCost(N, X , Y) << std::endl;

    return 0;
}