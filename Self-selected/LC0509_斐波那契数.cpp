/*
    题目：
        斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。
        该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
        给你 n ，请计算 F(n) 。
    思路：
        考虑动态规划。
        但是F(n)只与F(n-1)和F(n-2)有关，我们可以省去DP Table，只用两个变量存储F(n-1)和F(n-2)即可。
*/

class Solution {
public:
    int fib(int n) {
        if (n < 2)  return n;
        int F_n1 = 1;
        int F_n2 = 0;
        int F_n = 0;
        for (int i = 2; i <= n; ++i){
            F_n = F_n1 + F_n2;
            F_n2 = F_n1;
            F_n1 = F_n;
        }
        return F_n;
    }
};