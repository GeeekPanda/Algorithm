/*
    题目：
        有N件物品和一个容量是V的背包。每件物品只能使用一次。第i件物品的体积是vi，价值是wi。
        求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

        输入格式
            第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
            接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
        输出格式
            输出一个整数，表示最大价值。
        数据范围
            0<N,V≤1000
            0<vi,wi≤1000
        输入样例
            4 5
            1 2
            2 4
            3 4
            4 5
        输出样例：
            8
*/

#include <iostream>
#include <vector>
#include <algorithm>

int GetMaxWorth(const std::vector<std::vector<int> > vec, const int volume){
    const int rows = vec.size();
    std::vector<std::vector<int> > dp(rows, std::vector<int>(volume+1, 0));
    for(int i = 1; i < rows; ++i){
        for(int j = 1; j <= volume; ++j){
            if(j < vec[i][0])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-vec[i][0]] + vec[i][1]);
        }
    }
    return dp[rows-1][volume];
}

int main(){
    int nums = 0;
    int volume = 0;
    std::cin >> nums >> volume;
    std::vector<std::vector<int> > vec(nums+1, std::vector<int>(2, 0));
    for(int i = 1; i <= nums; ++i){
        for(int j = 0; j < 2; ++j)
            std::cin >> vec[i][j];
    }
    std::cout << GetMaxWorth(vec, volume) << std::endl;

    return 0;
}