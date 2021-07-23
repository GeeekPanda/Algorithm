/*
    思路：
        选取矩阵右上角元素与target比较：
            1. 若当前右上角元素值等于target，则返回true；
            2. 若当前右上角元素大于target，说明当前右上角元素所在列不可能存在target，若存在target，必在左边的列，这样可以剔除一列；
            3. 若当前右上角元素小于target，说明当前右上角元素所在行不可能存在target，若存在target，必在下边的行，这样可以剔除一行；
            4. 比到最后仍没有，说明不存在target，返回false。
*/
bool Find(int target, std::vector<std::vector<int> > array){
    const int rows = array.size();
    const int cols = array[0].size();
    bool found = false;
    if (rows > 0 && cols > 0){
        int row = 0;
        int col = cols - 1;
        while (row < rows && col >= 0 ){
            if (array[row][col] == target){
                found = true;
                break;
            }
            else if (target > array[row][col])
                ++row;
            else
                --col;
        }
    }
    return found;
}
