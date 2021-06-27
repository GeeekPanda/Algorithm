/*
    难度：简单

    题目：给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
         如果两个链表没有交点，返回 null 。
    
    思路：定义两个指针分别指向两个链表的头节点；
         然后一个节点一个节点的遍历；
         遍历完当前链表，就重新指向另一链表的头节点，继续遍历；
         两指针相遇的地方就是相交链表的相交点。
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if(headA == nullptr || headB == nullptr)
        return nullptr;
    
    ListNode* ptrA = headA;
    ListNode* ptrB = headB;

    while(ptrA != ptrB){
        ptrA = ptrA ? ptrA->next : headB;
        ptrB = ptrB ? ptrB->next : headA;
    }
    return ptrA;
}