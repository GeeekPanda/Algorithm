/*
    题目：
        输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
        假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
        序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
    思路：
        将pushV依次压入栈，并按照popV的顺序依次弹出。
        1. 若popV中下一个数字刚好是栈顶数字，那么直接弹出；
        2. 若popV中下一个数字不在栈顶，则将依次将剩余的pushV中的数字压入栈，直至popV中下一个数字入栈；
        3. 若pushV全入栈了，还是没有popV中下一个数字，则popV序列不是一个弹出序列。
*/

bool IsPopOrder(vector<int> pushV,vector<int> popV){
    const int size = pushV.size();
    std::stack<int> stk;
    int index_popV = 0;
    for(int num : pushV){
        stk.push(num);
        while(!stk.empty() && stk.top() == popV[index_popV]){
            stk.pop();
            ++index_popV;
        }
    }
    return stk.empty();
}