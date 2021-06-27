/*
    题目：
        输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
        对应每个测试案例，输出两个数，小的先输出。
    思路：
        对撞双指针：i指向头，j指向尾：
            1. 若curSum = array[i] + array[j],直接输出{i,j};
            2. 若curSum > array[i] + array[j],则--j;
            2. 若curSum < array[i] + array[j],则++i。
*/

vector<int> FindNumbersWithSum(vector<int> array,int sum){
    const int size = array.size();
    int left = 0;
    int right = size - 1;
    while(left < right){
        int curSum = array[left] + array[right];
        if(curSum == sum)
            return {array[left], array[right]};
        else if(curSum > sum)
            --right;
        else
            ++left;
    }
    return {};
}