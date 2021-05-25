#include <vector>
#include <stdio.h>

bool Find(int target, std::vector<std::vector<int>> array){
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
