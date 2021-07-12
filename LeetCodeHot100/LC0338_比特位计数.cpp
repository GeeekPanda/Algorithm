/*
    题目：
        给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
    思路：
        对于所有的数字，只有两类：
            奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，多的就是最低位的 1。
            偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。
                  因为最低位是 0，除以2就是右移一位，也就是把那个0抹掉而已，所以1的个数是不变的。
*/

class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> res(n+1);
        res[0] = 0;
        for(int i = 1; i <= n; ++i){
            if(i & 1 == 1){
                res[i] = res[i-1] + 1;
            }
            else{
                res[i] = res[i >> 1];
            }
        }
        return res;
    }
};