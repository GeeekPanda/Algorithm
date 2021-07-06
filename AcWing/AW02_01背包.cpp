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
        输出样例
            8
    
    思路：
        动态规划。
*/

#include <iostream>
#include <vector>
#include <algorithm>

int GetMaxWorth(const std::vector<std::vector<int> > para_goods_info, const int para_bag_volume){
    const int goods_num = para_goods_info.size() - 1;
    std::vector<std::vector<int> > dp(goods_num+1, std::vector<int>(para_bag_volume+1, 0));
    for(int i = 1; i <= goods_num; ++i){
        for(int j = 1; j <= para_bag_volume; ++j){
            if(j < para_goods_info[i][0])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = std::max(dp[i-1][j], para_goods_info[i][1]+dp[i-1][j-para_goods_info[i][0]]);
        }
    }
    return dp[goods_num][para_bag_volume];
}

int main(){
    int N = 0;
    int V = 0;
    std::cin >> N >> V;
    std::vector<std::vector<int> > goods_info(N+1, std::vector<int>(2, 0));
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < 2; ++j){
            std::cin >> goods_info[i][j];
        }
    }
    std::cout << GetMaxWorth(goods_info, V) << std::endl;
    return 0;
}