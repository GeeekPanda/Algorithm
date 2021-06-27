/*
    思路：
        打印节点值是一个读操作，我们尽量不应该修改原链表的结构，所以不建议反转链表之后再输出。
        从头遍历，从尾输出，这是典型的“先进后出”，应该采用栈。
*/
std::vector<int> printListInReversedOrder(ListNode* head){
    ListNode* curNode = head;
    std::stack<ListNode*> stk;
    std::vector<int> res;
    while (curNode != nullptr){
        stk.push(curNode);
        curNode = curNode->next;
    }
    while (!stk.empty())
    {
        curNode = stk.top();
        stk.pop();
        res.push_back(curNode->val);
    }
    
    return res;
}