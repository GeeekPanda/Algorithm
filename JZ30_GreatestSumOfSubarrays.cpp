/*
    题目：
        输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
        要求时间复杂度为 O(n).
    思路：
        动态规划。

*/

int FindGreatestSumOfSubArray(vector<int> array){
    const int size = array.size();
    vector<int> dp(size+1, 1);
    dp[0] = 0;
    int ret = array[0];
    for(int i = 1; i <= size; ++i){
        dp[i] = max(array[i-1], dp[i-1]+array[i-1]);
        ret = max(ret, dp[i]);
    }
    return ret;
}