/*
    题目：
        给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/


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