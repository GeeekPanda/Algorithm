/*
    难度：简单

    题目：给定一个链表，判断链表中是否有环。

    思路：快慢指针法。
         慢指针一次走一步，快指针一次走两步。
         若有环，两指针必相遇。
*/

bool hasCycle(ListNode *head){
    if(head == nullptr)
        return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(slow != fast){
        if(fast == nullptr || fast->next == nullptr)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}