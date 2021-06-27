/*
    题目：
        统计一个数字在升序数组中出现的次数。
    思路：
        1. 哈希表统计次数。
        2. 二分法。排序数组中的搜索问题，首先想到 二分法 解决
*/

// 哈希表统计次数
int GetNumberOfK(vector<int> data ,int k){
    std::unordered_map<int, int> mp;
    for(int num : data){
        ++mp[num];
    }
    return mp[k];
}

/*
    排序数组nums中的所有数字target形成一个窗口，
    记窗口的左/右边界索引分别为left和right，分别对应窗口左边/右边的首个元素。
    本题要求统计数字target的出现次数，可转化为：
    使用二分法分别找到左边界left和右边界right，易得数字target的数量为right-left-1。
*/
int GetNumberOfK(vector<int> data ,int k){
    const int size = data.size();
    int i = 0;
    int j = size - 1;
    //查找右边界
    //当data[mid] == k时，说明右边界在[mid, right]区间内，所以让i指向mid+1。
    while(i <= j){
        int mid = (i + j) >> 1;
        if(data[mid] > k)
            j = mid - 1;
        else if(data[mid] <= k)
            i = mid + 1;
    }
    int right = i;
    //查找左边界
    i = 0;
    j = size - 1;
    while(i <= j){
        int mid = (i + j) >> 1;
        if(data[mid] >= k)
            j = mid - 1;
        else if(data[mid] < k)
            i = mid + 1;
    }
    int left = j;

    return right-left-1;
}