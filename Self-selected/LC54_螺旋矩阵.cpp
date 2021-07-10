/*
    题目：
        给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/


//递归
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        getOuterRing(matrix, 0, rows-1, 0, cols-1);
        return result;
    }
private:
    std::vector<int> result;
    void getOuterRing(std::vector<std::vector<int> > &matrix, int rowStart, int rowEnd, int colStart, int colEnd){
        if(rowStart >= rowEnd || colStart >= colEnd){
            if(rowStart == rowEnd)
                for(int j = colStart; j <= colEnd; ++j) result.push_back(matrix[rowStart][j]);
            else if(colStart == colEnd)
                for(int i = rowStart; i <= rowEnd; ++i) result.push_back(matrix[i][colStart]);
            return;
        }
        int right = colStart;
        int down = rowStart;
        int left = colEnd;
        int up = rowEnd;
        while(right < colEnd)  result.push_back(matrix[rowStart][right++]);
        while(down < rowEnd)    result.push_back(matrix[down++][colEnd]);
        while(left > colStart)  result.push_back(matrix[rowEnd][left--]);
        while(up > rowStart)    result.push_back(matrix[up--][colStart]);
        getOuterRing(matrix, rowStart+1, rowEnd-1, colStart+1, colEnd-1);
    }
};