/*
    思路：
        其实还是Fibonacci问题。
*/

int jumpFloor(int number){
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