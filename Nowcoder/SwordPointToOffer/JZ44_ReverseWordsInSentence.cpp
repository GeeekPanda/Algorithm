/*
    题目：
        牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
        同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
        例如，“nowcoder. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
        正确的句子应该是“I am a nowcoder.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
    思路：
        从不是空格的字符开始到空格的前一个字符结束，即为一个单词。
        考虑双指针倒序遍历序列：
            1. 倒序遍历字符串str,记录单词左右索引边界i,j;
            2. 每确定一个单词的边界，就将其添加至res;
*/

string ReverseSentence(string str){
    const int size = str.size();
    if(size == 0)
        return str;
    string res;
    int right = size - 1;
    while(right >= 0){
        while(right >=0 && str[right] == ' ')
            --right;
        if(right < 0)
            break;
        int left = right;
        while(left >= 0 && str[left] != ' ')
            --left;
        res.append(str, left+1, right-left);
        res.append(" ");

        right = left;
    }
    if (!res.empty()) 
        res.pop_back();
    return res;
}