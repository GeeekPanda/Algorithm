/*
    题目：
        输入两个无环的单链表，找出它们的第一个公共结点。
    思路：
        双指针法。
        1. 首先定义i、j分别指向两链表的头节点；
        2. 通过i、j遍历两个链表，遍历到尾时，指向另一链表的头节点，继续遍历；
           如，i遍历完pHead1后，i指向pHead2的头节点，继续遍历pHead2.
        3. 当i、j相遇时，即为两链表第一个公共节点。
*/

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2){
    ListNode* i = pHead1;
    ListNode* j = pHead2;

    while(i != j){
        i = i ? i->next : pHead2;
        j = j ? j->next : pHead1;
    }

    return i;
}