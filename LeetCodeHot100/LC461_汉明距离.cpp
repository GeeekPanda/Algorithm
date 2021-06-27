/*
    难度：简单
    
    题目：两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
         给你两个整数x和y，计算并返回它们之间的汉明距离。
    
    思路：取两数异或结果为z，这样z中1的个数就是最终答案。
         通过右移z，将z的每一位与1进行与操作，若为1，则count加1。
         直至z为0，终止循环，返回count即可。
*/

int hammingDistance(int x, int y) {
    int count = 0;
    int z = x ^ y;
    while(z){
        if(z & 1)
            ++count;
        z >>= 1;
    }
    return count;
    }
