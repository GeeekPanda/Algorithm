/*
    题目：
        在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
        数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
        请找出数组中任意一个重复的数字。 
        例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，那么对应的输出是2或者3。存在不合法的输入的话输出-1。
    思路：
        按照题意，如果没有重复数字，那么排序后，数字i应该在下标i处，即index与numbers[index]一一对应；
        但如果有重复数字，必然不能满足上边的情况。
        我们从头扫描数组，遍历中，第一次遇到数字x时，将其交换至索引x处；
        而当第二次遇到数字x时，一定有nums[x] = x，此时即可得到一组重复数字。
*/

int duplicate(vector<int>& numbers){
    const int size = numbers.size();
    int i = 0;
    while(i < size){
        if(numbers[i] == i){
            ++i;
            continue;
        }
        if(numbers[i] == numbers[numbers[i]])
            return numbers[i];
        swap(numbers[i], numbers[numbers[i]]);
    }
    return -1;
}