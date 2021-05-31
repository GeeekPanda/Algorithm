/*
    题目：
        在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置;
        如果没有则返回 -1（需要区分大小写）.（从0开始计数）.
    思路：
        哈希表
*/

int FirstNotRepeatingChar(string str){
    unordered_map<char, int> mp;
    for(char ch : str)
        ++mp[ch]; //如果ch还不在map中，下标运算符会添加一个新元素。
    for(int i = 0; i < str.size(); ++i){
        if(mp[str[i]] == 1)
            return i;
    }
    return -1;
}
