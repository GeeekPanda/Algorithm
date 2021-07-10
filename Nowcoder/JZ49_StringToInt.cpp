/*
    题目：
        将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
        数值为0或者字符串不是一个合法的数值则返回0。
        输入：一个字符串,包括数字字母符号,可以为空
        返回值：如果是合法的数值表达则返回该数字，否则返回0
    思路：
        输入的合法字符串包含数字字母和符号，可以为空。
            1. 若为空，返回0；
            2. 若含有字母，返回0；
            3. 第一个字符是'+'或'-'，表示正负，是合法的；其他符号是非法的，返回0；
        int的范围是-2147483648~2147483647;
*/

int StrToInt(string str){
    const int size = str.size();
    if(size == 0)
        return 0;
    int res = 0;
    int sign = 1;
    int firstNum = 1;
    if(str[0] == '-')
        sign = -1;
    else if(str[0] != '+')
        firstNum = 0;
    for(int i = firstNum; i < size; ++i){
        if(str[i] < '0' || str[i] > '9' || res > __INT32_MAX__ || res < INT32_MIN)
            return 0;
        res = res * 10 + (str[i] - '0');
    }
    return sign*res;
}