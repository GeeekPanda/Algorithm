/*
    题目：
        在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
        请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        int i = 0;
        int j = m-1;
        while(i < n && j >= 0){
            if(matrix[i][j] > target)
                --j;
            else if(matrix[i][j] < target)
                ++i;
            else
                return true;
        }
        return false;
    }
};