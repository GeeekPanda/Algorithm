/*
    题目：
        输入一个整数数组，实现一个函数来调整该数组中数字的顺序：
        使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。
    思路：
        考虑双指针
*/

vector<int> exchange(vector<int>& nums){
    const int size = nums.size();
    int i = 0;
    int j = size - 1;
    while(i < j){
        if((nums[i] & 0x1) && !(nums[j] & 0x1)){
            ++i;
            --j;
        }
        else if((nums[i] & 0x1) && (nums[j] & 0x1)){
            ++i;
        }
        else if(!(nums[i] & 0x1) && (nums[j] & 0x1)){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            ++i;
            --j;
        }
        else{
            --j;
        }
    }
    return nums;
}