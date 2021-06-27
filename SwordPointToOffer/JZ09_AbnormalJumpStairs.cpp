/*
    题目：
        一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法？
    思路：
        f(n) = f(n-1) + f(n-2) + ... +f(0)
        f(n-1) = f(n-2) + f(n-3) + ... +f(0)
        故f(n) = 2*f(n-1)
        初始条件：f(0) = 1, f(1) = 1。
*/

int JumFloorII(int number){
    if(number < 2)   return 1;
    int a = 1; //a就是f(n-1)
    int b = 0; //b就是f(n)
    for(int i = 2; i <= number; ++i){
        b = a << 1; //f(n)=2*f(n-1)
        a = b;
    }
    return b;
}