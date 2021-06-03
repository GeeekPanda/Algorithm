/*
    题目：
        汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
        对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
        例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
    思路：
        三次翻转法。如 abcXYZdef << 3 == XYZdefabc
        1. 先反转前n个字符，翻转后得cbaXYZdef;
        2. 再翻转后边的字符，翻转后得cbafedZYX;
        3. 整体翻转，翻转后得XYZdefabc。
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        const int size = str.size();
        if(size == 0)
            return str;
        StringReverse(str, 0, n-1);
        StringReverse(str, n, size-1);
        StringReverse(str, 0, size-1);
        return str;
    }
private:
    void StringReverse(string &str, int start, int end){
        for(int i = start; i <= (start + end) >> 1; ++i){
            char temp = str[i];
            str[i] = str[start+end-i];
            str[start+end-i] = temp;
        }
    }
};