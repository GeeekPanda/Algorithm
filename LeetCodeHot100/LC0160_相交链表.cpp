/*
    题目：
        给你两个单链表的头节点 headA 和 headB，
        请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB){
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};