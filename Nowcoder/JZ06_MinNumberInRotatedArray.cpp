/*
    思路：
        旋转后的数组其实可以划分为两个排序的子数组，且前面的子数组元素值>=后边的子数组元素值，同时最小的元素是两数组的分界线。
        试着用二分法的思路来寻找这个最小元素：
            1. 两个指针i，j分别指向数组的第一个元素和最后一个元素；
            2. 根据两指针找到中间元素：
                若中间元素大于/等于i指向的元素，说明中间元素在前边的子数组，最小元素应该在中间元素后边。我们让i指向中间元素，减小寻找范围；
                若中间元素小于/等于j指向的元素，说明中间元素在后边的子数组，最小元素应该在中间元素前边。我们让j指向中间元素，减小寻找范围；
            3. 根据更新后的指针继续上述过程。
            4. 最终i，j会指向相邻元素，且j指向的就是最小元素。
        但有两个特例需要注意：
            1. 原数组也是旋转的一个特例，此时第一个元素就是最小元素。所以一旦发现第一个元素小于最后一个元素，直接返回第一个元素即可。
            2. 上述二分查找过程无法处理i、j所指向元素及中间元素三者相等的情况，对于这种情况，只能采取顺序查找。
                
*/
int minNumberInRotateArray(vector<int> rotateArray){
    const int size = rotateArray.size();
    int index_i = 0;
    int index_j = size - 1;
    int index_mid = index_i;    //初始化为index_i，处理特例1
    while(rotateArray[index_i] >= rotateArray[index_j]){
        if(index_j - index_i == 1){
            index_mid = index_j;
            break;
        }
        index_mid = (index_i + index_j) / 2;
        //若index_i、index_j、index_mid三者指向的元素相等，则采取顺序查找
        if(rotateArray[index_i] == rotateArray[index_j] && rotateArray[index_mid] == rotateArray[index_i])
            return minInOrder(rotateArray, index_i, index_j);
        if(rotateArray[index_i] <= rotateArray[index_mid])
            index_i = index_mid;
        else if(rotateArray[index_j] >= rotateArray[index_mid])
            index_j = index_mid;
    }
    return rotateArray[index_mid];
}

int minInOrder(vector<int> rotateArray, int index_i, int index_j){
    int result = rotateArray[index_i];
    for(int i = index_i + 1; i <= index_j; ++i){
        if(rotateArray[i] < result)
            result = rotateArray[i];
    }
    return result;
}