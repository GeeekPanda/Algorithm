/*
    题目：
        我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
        请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，从同一个方向看总共有多少种不同的方法？
    思路：
        其实质还是Fibonacci数列问题。
*/

int rectCover(int number){
    if(number < 3)
        return number;
    int preOne = 2;
    int preTwo = 1;
    int result = 0;
    for(int i = 3; i <= number; ++i){
        result = preOne + preTwo;
        preTwo = preOne;
        preOne = result;
    }
    return result;
}