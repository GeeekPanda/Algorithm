/*
    题目：
        给你一个字符串 s，找到 s 中最长的回文子串
*/

class Solution {
public:
    string longestPalindrome(string s) {
        const int size = s.size();
        if(size < 2)    return s;
        int maxLen = 1;
        int begin = 0;
        std::vector<std::vector<bool> > dp(size,std::vector<bool>(size, false));
        for(int i = 0; i < size; ++i){
            dp[i][i] = true;
        }
        for(int subLen = 2; subLen <= size; ++subLen){
            for(int leftBoundary = 0; leftBoundary < size; ++leftBoundary){
                int rightBoundary = subLen + leftBoundary - 1;
                if(rightBoundary >= size)   break;
                if(s[leftBoundary] != s[rightBoundary])
                    dp[leftBoundary][rightBoundary] = false;
                else{
                    if(rightBoundary - leftBoundary < 3)
                        dp[leftBoundary][rightBoundary] = true;
                    else
                        dp[leftBoundary][rightBoundary] = dp[leftBoundary+1][rightBoundary-1];
                }
                if(dp[leftBoundary][rightBoundary] && rightBoundary-leftBoundary+1 > maxLen){
                    maxLen = rightBoundary - leftBoundary + 1;
                    begin = leftBoundary;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};