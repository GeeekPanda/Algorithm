/*
    题目：
        定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O(1)）。
    思路：
        用辅助栈实现。辅助栈的栈顶元素就是数据栈中当前所有元素的最小值。
*/

class Solution {
public:
    void push(int value) {
        stk_data.push(value);
        if(!stk_help.empty()){
            if(value > stk_help.top())
                stk_help.push(stk_help.top());
            else
                stk_help.push(value);
        }
        else
            stk_help.push(value);
    }
    void pop() {
        stk_data.pop();
        stk_help.pop();
    }
    int top() {
        int top = stk_data.top();
        return top;
    }
    int min() {
        int min = stk_help.top();
        return min;
    }
private:
    std::stack<int> stk_data;
    std::stack<int> stk_help;
};