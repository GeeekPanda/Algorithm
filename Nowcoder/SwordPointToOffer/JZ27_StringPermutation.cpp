/*
    题目：
        输入一个字符串,按字典序打印出该字符串中字符的所有排列。
        例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
    思路：
        对于一个长度为n的字符串（假设字符互不重复），其排列方案数共有：n×(n−1)×(n−2)…×2×1
        1. 排列方案的生成：
             根据字符串排列的特点，考虑深度优先搜索所有排列方案。
             即通过字符交换，先固定第1位字符（n种情况）、再固定第2位字符（n−1种情况）、... 、最后固定第n位字符（1种情况）。
        2. 重复排列方案与剪枝：
             当字符串存在重复字符时，排列方案中也存在重复的排列方案。
             为排除重复方案，需在固定某位字符时，保证 “每种字符只在此位固定一次” ，即遇到重复字符时不交换，直接跳过。
             从 DFS 角度看，此操作称为 “剪枝” 。
*/

class Solution {
public:
    std::vector<std::string> Permutation(std::string str) {
        dfs(str, 0);
        return res;
    }
private:
    std::vector<std::string> res;
    void dfs(std::string str, int index_pin){
        const int size = str.size();
        if(index_pin == size-1){
            res.push_back(str);
            return;
        }
        std::set<int> st;
        for(int i = index_pin; i < size; ++i){
            if(st.find(str[i]) != st.end())
                continue;
            st.insert(str[i]);
            swap(str[i], str[index_pin]);
            dfs(str, index_pin+1);
            swap(str[i], str[index_pin]);
        }
    }
};