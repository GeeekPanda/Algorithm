/*
    思路：
        两个栈实现队列。栈“先进后出”，队列“先进先出”。
        插入：无论stack2是否为空，都将新元素压入stack1即可。
                stack1        stack2
                |  c  |       |     |
                |  b  |       |     |
                |  a  |       |     |
        删除：
            1. stack2不为空：直接弹出stack2栈顶元素即可；
                stack1        stack2               stack1      stack2
                |     |       |     |             |     |      |     |
                |     |       |  b  |    ====>    |     |      |     |
                |  d  |       |  c  |             |  d  |      |  c  |

            2. stack2为空：将stack1元素逐个压入stack2，然后弹出栈顶元素即可。
                stack1        stack2              stack1       stack2
                |  c  |       |     |             |     |      |     |
                |  b  |       |     |    ====>    |     |      |  b  |
                |  a  |       |     |             |     |      |  c  |

*/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
        }
        int top = stack2.top();
        stack2.pop();
        return top;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};