/*
    题目：
        给你一个只包含正整数的非空数组nums。
        请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
    思路：
        给定一个只包含正整数的非空数组nums，判断是否可以从数组中选出一些数字，
        使得这些数字的和等于整个数组的元素和的一半。
        因此这个问题可以转换成「0-1背包问题」。
        这道题与传统的「0-1背包问题」的区别在于：
            传统的「0-10−1 背包问题」要求选取的物品的重量之和不能超过背包的总容量，
            这道题则要求选取的数字的和恰好等于整个数组的元素和的一半。

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int size = nums.size();
        if(size < 2)    return false;
        int sum = accmulate(nums.begin(), nums.end(), 0);
        int max = *max_element(nums.begin(), nums.end());
        if(sum & 1)    return false;
        int target = sum / 2;
        if(max > target)    return false;
    }
};