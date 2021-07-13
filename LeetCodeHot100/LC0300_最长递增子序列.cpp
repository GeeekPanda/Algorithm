/*
    题目：
        给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
        子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
        例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
    思路：
        动态规划
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        if(size < 2)    return size;
        std::vector<int> dp(size, 0);
        dp[0] = 1;
        for(int i = 1; i < size; ++i){
            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};