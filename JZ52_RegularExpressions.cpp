/*
    题目：
        请实现一个函数用来匹配包括'.'和'*'的正则表达式。
        模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
        在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。
    思路：
        '.'好处理，主要是'*'。
        当pattern[j+1]为'*'时，分几种情况讨论：
            1. 如果str[i] == pattern[j],有两种情况：
                1-1. pattern[j]可能匹配多个字符，比如str = "aaa",pattern = "a*",那么p[0]会通过'*'匹配3个字符'a';
                1-2. pattern[j]可能匹配0个字符，
                     比如str = "aa", pattern = "a*aa",由于后面的字符可以匹配str，所以p[0]只能通过'*'匹配0次。
            2. 如果str[i] != pattern[j],则只有一种情况：
                2-1. p[j]只能匹配0次，然后看下一个字符是否能和str[i]匹配。
                     比如str = "aa",pattern = "b*aa",str[0] != pattern[0],所以pattern[0]只能匹配0次。
*/
class Solution{
public:
    bool match(string str, string pattern){
        return dp(str, 0, pattern, 0);
    }
private:
    bool dp(string str, int i, string pattern, int j){
        const int str_size = str.size();
        const int ptn_size = pattern.size();

        if(j == ptn_size)
            return i == str_size;
        if(i == str_size){
            if((ptn_size - j) % 2 == 1)
                return false;
            for( ; j + 1 < ptn_size; j += 2){
                if(pattern[j+1] != '*')
                    return false;
            }
            return true;
        }

        bool res = false;
        if(str[i] == pattern[j] || pattern[j] == '.'){
            if(j < ptn_size - 1 && pattern[j+1] == '*')
                res = dp(str, i, pattern, j+2) || dp(str, i+1, pattern, j);
            else
                res = dp(str, i+1, pattern, j+1);
        }
        else{
            if(j < ptn_size - 1 && pattern[j+1] == '*')
                res = dp(str, i, pattern, j+2);
            else
                return false;
        }
        return res;
    }
};