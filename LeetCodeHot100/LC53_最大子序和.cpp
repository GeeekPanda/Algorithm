/*
    题目：
        给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int size = nums.size();
        if(size == 1)   return nums[0];
        std::vector<int> dp(size, 0);
        dp[0] = nums[0];
        int result = dp[0];
        for(int i = 1; i < size; ++i){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};


//空间优化版
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int res = nums[0];
        for(auto ele : nums){
            pre = max(pre+ele, ele);
            res = max(res, pre);
        }
        return res;
    }
};