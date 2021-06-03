/*
    题目：
        求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
    思路：
        不考虑限制的话，可以很简单的写出递归方法，
            int Sum_Solution(int n){
                if(n == 1) return 1;
                n += sumNums(n - 1);
                return n;
            }
        但递归的终止条件用到了if语句，我们想办法用别的来代替if作为终止条件。
        if(n == 1) return 1;也就是说如果n==1,需要终止递归;如果n不等于1，就执行下边的语句。
        所以我们想到了逻辑与&&连接符的短路效应。
        A&&B，表示如果A成立则执行B，否则如果A不成立，不用执行B
        因此我们可以这样。在n>1的时候，执行递归函数。
*/

int Sum_Solution(int n){
    bool x = n > 1 && (n += Sum_Solution(n-1));
    return n;
}
