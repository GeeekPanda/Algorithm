/*
    题目：
        输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
        1  2  3  4
        5  6  7  8           ====>     1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
        9  10 11 12
        13 14 15 16
    思路：
        一圈一圈地打印。
*/
vector<int> printMatrix(vector<int> > matrix){
    vector<int> result;
    const int rows = matrix.size();
    const int cols = matrix[0].size();
    
    //定义递归函数，此处采用lambda表达式
    std::function<void(int rowStart, int colStart, int rowEnd, int colEnd)> getOuterRing;
    getOuterRing = [&](int rowStart, int colStart, int rowEnd, int colEnd){
        if(rowStart >= rowEnd || colStart >= colEnd){
            if(rowStart == rowEnd)
                for(int j = colStart; j <= colEnd; ++j) result.push_back(matrix[rowStart][j]);
            else if(colStart == colEnd)
                for(int i = rowStart; i <= rowEnd; ++i) result.push_back(matrix[i][colStart]);
            return;
        }
        int rightStart = colStart;
        int downStart = rowStart;
        int leftStart = colEnd;
        int upStart = rowEnd;
        while(rightStart < colEnd)  result.push_back(matrix[rowStart][rightStart++]);
        while(downStart < rowEnd)   result.push_back(matrix[downStart++][colEnd]);
        while(leftStart > colStart) result.push_back(matrix[rowEnd][leftStart--]);
        while(upStart > rowStart)   result.push_back(matrix[upStart--][colStart]);
        getOuterRing(rowStart+1, colStart+1, rowEnd-1, colEnd-1);
    };

    getOuterRing(0, 0, rows-1, cols-1);
    return result;
}