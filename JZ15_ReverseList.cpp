/*
    题目：
        输入一个链表，反转链表后，输出新链表的表头。
    思路：
        定义三个指针：curr指向当前遍历的节点；
                     prev指向curr的前一个节点，curr->next = prev即完成cur节点的反转；
                     next指向curr的下一个节点，反转后无法再用curr找到下个节点，所以要用next提前保存curr的下一个节点。
*/

ListNode* ReverseList(ListNode* pHead){
    ListNode* prev = nullptr;
    ListNode* curr = pHead;
    ListNode* next = nullptr;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}