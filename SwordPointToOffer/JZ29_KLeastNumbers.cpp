/*
    题目：
        给定一个数组，找出其中最小的K个数。
        例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。如果K>数组的长度，那么返回一个空的数组。
    思路：
        快速排序原理：快速排序算法有两个核心点，分别为 “哨兵划分” 和 “递归” 。
            哨兵划分操作： 以数组某个元素（一般选取首元素）为 基准数 ，将所有小于基准数的元素移动至其左边，大于基准数的元素移动至其右边。
            递归： 对 左子数组 和 右子数组 递归执行 哨兵划分，直至子数组长度为 1 时终止递归，即可完成对整个数组的排序。
        基于快速排序的数组划分：
            题目只要求返回最小的k个数，对这k个数的顺序并没有要求。因此，只需要将数组划分为最小的k个数和其他数字两部分即可。
            根据快速排序原理，如果某次哨兵划分后基准数正好是第k+1小的数字，那么此时基准数左边的所有数字便是题目所求的最小的k个数 。
            根据此思路，考虑在每次哨兵划分后，判断基准数在数组中的索引是否等于k ，若true则直接返回此时数组的前k个数字即可。
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size())
            return {};
        if(k == input.size())
            return input;
        return quickSort(input, k, 0, input.size()-1);
    }
private:
    vector<int> quickSort(vector<int> input, int k, int left, int right){
        int i = left;
        int j = right;
        while(i < j){
            while(i < j && input[left] <= input[j])
                --j;
            while(i < j && input[left] >= input[i])
                ++i;
            swap(input[i], input[j]);
        }
        swap(input[i], input[left]);
        if(i > k)
            return quickSort(input, k, left, i-1);
        if(i < k)
            return quickSort(input, k, i+1, right);
        vector<int> result;
        result.assign(input.begin(), input.begin()+k);
        return result;
    }
};