/*
    题目：
        输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
    思路：
        1. 考虑递归过程。
        2. 双指针
*/

//递归
ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(pHead1 == nullptr)
        return pHead2;
    else if(pHead2 == nullptr)
        return pHead1;

    ListNode* pMergeHead = nullptr;
    if(pHead1->val < pHead2->val){
        pMergeHead = pHead1;
        pMergeHead->next = Merge(pHead1->next, pHead2);
    }
    else{
        pMergeHead = pHead2;
        pMergeHead->next = Merge(pHead1, pHead2->next);
    }
    return pMergeHead;
}

//双指针
ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    //若某一链表为空，直接返回另一链表
    if(pHead1 == nullptr)
        return pHead2;
    else if(pHead2 == nullptr)
        return pHead1;
    //伪头节点preHead和新链表的尾节点newTail
    ListNode* preHead = new ListNode(-1);
    ListNode* newTail = preHead;
    //双指针
    ListNode* curNode_1 = pHead1;
    ListNode* curNode_2 = pHead2;

    while(curNode_1 && curNode_2){
        if(curNode_1->val < curNode_2->val){
            newTail->next = curNode_1;
            curNode_1 = curNode_1->next;
        }
        else{
            newTail->next = curNode_2;
            curNode_2 = curNode_2->next;
        }
        newTail = newTail->next;
    }
    newTail->next = curNode_1 != nullptr ? curNode_1 : curNode_2;
    return preHead->next;
}