/*
    题目：
        在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
        输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
        示例: 输入：[1,2,3,4,5,6,7,0]      输出：7
    思路：
        「归并排序」与「逆序对」是息息相关的。归并排序体现了 “分而治之” 的算法思想，具体为：
            分：不断将数组从中点位置划分开（即二分法），将整个数组的排序问题转化为子数组的排序问题；
            治：划分到子数组长度为 1 时，开始向上合并，不断将 较短排序数组 合并为 较长排序数组，直至合并至原数组时完成排序。
        合并阶段本质上是合并两个排序数组的过程，而每当遇到左子数组当前元素>右子数组当前元素时，
        意味着「左子数组当前元素 至 末尾元素」 与「右子数组当前元素」构成了若干「逆序对」 。
*/

class Solution {
public:
    int InversePairs(vector<int> data) {
        int ret = 0;
        vector<int> tmp(data.size());
        mergeSort(data, tmp, 0, data.size() - 1, ret);
        return ret;
    }
private:
    const int kmod = 1000000007;
    void mergeSort(vector<int> &arr, vector<int> &tmp, int left, int right, int &ret) {
        if (left >= right)
            return;
        int mid = left + ((right - left) >> 1);
        mergeSort(arr, tmp, left, mid, ret);
        mergeSort(arr, tmp, mid + 1, right, ret);
        merge(arr, tmp, left, mid, right, ret);
    }
    void merge(vector<int> &arr, vector<int> &tmp, int left, int mid, int right, int &ret) {
        int i = left; 
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right) {
            if (arr[i] > arr[j]) {
                tmp[k++] = arr[j++];
                ret += (mid - i + 1);
                ret %= kmod;
            }
            else 
                tmp[k++] = arr[i++];
        }
        while (i <= mid) 
            tmp[k++] = arr[i++];
        while (j <= right) 
            tmp[k++] = arr[j++];
        for (k = 0, i = left; i <= right; ++i, ++k) 
            arr[i] = tmp[k];
    }
};