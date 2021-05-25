#include <vector>
#include <stdio.h>

using namespace std;

bool Find(int target, vector<vector<int> > array){
    //选取右上角值作为“哨兵”，与target作比较
    const int row_size = array.size();
    const int col_size = array[0].size();
    int row_num = 0;
    int col_num = col_size - 1;
    int guard = array[row_num][col_num];
    while(0 <= row_num &&  )
    if(target == guard)
        return true;
    else if(target > guard)
    else

}