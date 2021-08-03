/*
    题目：
        找出数组中重复的数字。
        在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
        数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
        请找出数组中任意一个重复的数字。
*/


//法一：哈希表
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::unordered_map<int, bool> dic;
        for(int e : nums){
            if(dic[e])
                return e;
            dic[e] = true;
        }
        return -1;
    }
};

//原地交换
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        const int size = nums.size();
        int i = 0;
        while(i < size){
            if(nums[i] == i){
                ++i;
                continue;
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};