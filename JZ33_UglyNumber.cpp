/*
    题目：
        把只包含质因子2、3和5的数称作丑数（Ugly Number）。
        例如6、8都是丑数，但14不是，因为它包含质因子7。 
        习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
    思路：
        丑数的递推性质：丑数只包含因子2, 3, 5，因此有 “丑数=某较小丑数×某因子” （例如：10=5×2）。
*/

int GetUglyNumber_Solution(int index){
    if(index <= 0)
        return 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int dp[index];
    dp[0] = 1;
    for(int i = 1; i < index; ++i){
        int n2 = dp[a] * 2;
        int n3 = dp[b] * 3;
        int n5 = dp[c] * 5;
        dp[i] = min(min(n2, n3), n5);
        if(dp[i] == n2)
            ++a;
        if(dp[i] == n3)
            ++b;
        if(dp[i] == n5)
            ++c;
    }
    return dp[index-1];
}