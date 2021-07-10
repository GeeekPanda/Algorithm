/*
    题目：
        设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
*/


//直接用STL里的priority_queue(大根堆)
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        std::vector<int> res(k, 0);
        if(k == 0)  return res;
        std::priority_queue<int> maxHeap;
        for(int i = 0; i < k; ++i)
            maxHeap.push(arr[i]);
        for(int i = k; i < arr.size(); ++i){
            if(maxHeap.top() > arr[i]){
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        for(int i = 0; i < k; ++i){
            res[i] = maxHeap.top();
            maxHeap.pop();
        }
        return res;
    }
};
//自己实现大根堆
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {

    }
private:
    void buildMinHeap(std::vector<int>& arr, int index, int heapSize){
        int dad = index;
        int leftSon = 2*dad + 1;
        while(leftSon < heapSize){
            int smallest = leftSon+1 < heapSize && arr[leftSon+1] > arr[leftSon] ? 
        }
    }
};