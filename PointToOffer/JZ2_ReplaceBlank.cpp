/*
    思路：
        1. 首先遍历一次，统计出s中含有的空格个数；
        2. 将s的大小resize为替换之后的大小：旧大小+空格数*2；
        3. 双指针法。i指向最后一个元素，j指向扩容后最后一个位置；
*/
std::string replaceBlank(std::string s){
    const int sOldSize = s.size();
    int countOfBlank = 0;
    for(char c : s){
        if (c == ' ')
            ++countOfBlank;    
    }
    s.resize(sOldSize + countOfBlank*2);
    const int sNewSize = s.size();
    int i = sOldSize - 1;
    int j = sNewSize - 1;
    while(i != j){
        if (s[i] != ' '){
            s[j] = s[i];
            --i;
            --j;
        }
        else{
            s[j] = '0';
            s[j-1] = '2';
            s[j-2] = '%';
            j -= 3;
            --i;
        }
    }
    return s;
}