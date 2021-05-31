/*
    题目：
        输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数
        例如，1~13中包含1的数字有1、10、11、12、13因此共出现6次
    思路：
        将1~n的个位、十位、百位、...的1出现次数相加，即为1出现的总次数。
*/

int NumberOf1Between1AndN_Solution(int n){
    int digit = 1;
    int result = 0;
    int high = n / 10;
    int cur = n % 10;
    int low = 0;
    while(high != 0 || cur != 0){
        if(cur == 0)
            result += high * digit;
        else if(cur == 1)
            result += high * digit + low + 1;
        else
            result += (high + 1) * digit;
        low += cur * digit;
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }
    return result;
}