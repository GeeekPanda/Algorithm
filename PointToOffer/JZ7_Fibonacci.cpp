/*
    思路：
        1.最简单的肯定是基础版递归：
                if(n < 2)   return n;
                return Fibonacci(n-1) + Fibonacci(n-2);
          这种非常低效，因为会产生很多重复计算，不是面试官期待的。
        2.我们可以采取从下往上计算的方式，即先通过f(0)和f(1)计算出f(2),再根据f(1)和f(2)计算出f(3),...,以此类推。
          这种方法是比较实用的。
*/

int Fibonacci(int n){
    if(n < 2)
        return n;
    int preOne = 1;
    int preTwo = 0;
    int result = 0;
    for(int i = 2; i <= n; ++i){
        result = preOne + preTwo;
        preTwo = preOne;
        preOne = result;
    }
    return result;
}