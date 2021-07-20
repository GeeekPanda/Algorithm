/*
    题目：
        给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，
        只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        const int size = pushed.size();
        std::stack<int> stk;
        int idx_pushed = 0;
        int idx_poped = 0;
        while(idx_poped < size){
            while(idx_pushed < size && (stk.empty() || stk.top() != popped[idx_poped]))
                stk.push(pushed[idx_pushed++]);
            if(idx_pushed == size && stk.top() != popped[idx_poped])
                return false;
            while(idx_poped < size && !stk.empty() && stk.top() == popped[idx_poped]){
                stk.pop();
                ++idx_poped;
            }
        }
        return true;
    }
};