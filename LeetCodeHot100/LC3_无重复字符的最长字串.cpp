/*
    题目：
        给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
    思路：
        动态规划
        定义dp[i]为以s[i]为结尾的字符串的不含重复字符的最长字串的长度。
        dp[i]可分为两种情况：
            如果s[i]在之前从没出现过，那么加入它，dp[i]=dp[i-1]+1；
            如果s[i]之前出现过，就需要找出它最近出现的位置j：
                若i-j > dp[i-1]，说明dp[i-1]不包含这个元素，可以把他加入，dp[i]=dp[i-1]+1；
                若i-j <= dp[i-1]，说明dp[i-1]内已经包含了一个该元素，那dp[i-1]就废掉了，dp[i]应该是从s[j+1]到s[i]元素的长度i-j,dp[i] = i - j;
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int size = s.size();
        if(size < 2)    return size;
        std::vector<int> dp(size, 0);
        dp[0] = 1;
        int res = dp[0];
        for(int i = 1; i < size; ++i){
            int j = i - 1;
            for(; j >= 0; --j){
                if(s[j] == s[i])
                    break;
            }
            if(j == 0 && s[0] != s[i])
                dp[i] = dp[i-1] + 1;
            else{
                if((i-j) > dp[i-1])
                    dp[i] = dp[i-1] + 1;
                else
                    dp[i] = i - j;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};