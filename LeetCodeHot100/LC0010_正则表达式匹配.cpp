/*
    难度：
        困难
    题目：
        给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
        '.' 匹配任意单个字符
        '*' 匹配零个或多个前面的那一个元素
        所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();

        auto matches = [&] (int i, int j){
            if(i == 0)
                return false;
            if(p[j-1] == '.')
                return true;
            return s[i-1] == p[j-1];
        };

        std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1));
        dp[0][0] = true;
        for(int i = 0; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(p[j-1] == '*'){
                    dp[i][j] 
                }
            }
        }
    }
};