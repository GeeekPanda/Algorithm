/*
    题目：
        现在有2副扑克牌，从扑克牌中随机五张扑克牌，我们需要来判断一下是不是顺子。
        有如下规则：
            1. A为1，J为11，Q为12，K为13，A不能视为14
            2. 大、小王为 0，0可以看作任意牌
            3. 如果给出的五张牌能组成顺子（即这五张牌是连续的）就输出true，否则就输出false。
        例如：给出数据[6,0,2,0,4]
        中间的两个0一个看作3，一个看作5 。即：[6,3,2,5,4]
        这样这五张牌在[2,6]区间连续，输出true
        数据保证每组5个数字，每组最多含有4个零，数组的数取值为 [0, 13]
    思路：
        满足以下条件，抽取的牌得满足以下条件：
            1. 除了王以外，五张牌中没有重复的；
            2. 除了王以外，剩下的牌中的max-min<5。
        两副牌，有四个王，假设其他牌不重复，并将五张牌排序，则有以下其中可能：
            没有王：ABCDE
            一个王：0BCDE
            两个王：00CDE
            三个王：000DE
            四个王：0000E （必成顺子）
*/

bool IsContinuous( vector<int> numbers ){
    int joker = 0;
    sort(numbers.begin(), numbers.end());
    for(int i = 0; i < 4; ++i){
        if(numbers[i] == 0)
            ++joker;
        else if(numbers[i] == numbers[i+1])
            return false;
    }
    return numbers[4] - numbers[joker] < 5;
}