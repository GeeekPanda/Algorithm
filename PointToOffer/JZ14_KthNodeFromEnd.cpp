/*
    题目：
        输入一个链表，输出该链表中倒数第k个结点。
        如果该链表长度小于k，请返回空。
    思路：
        采用双指针，只遍历一次解决问题：
        i、j均指向头节点，i先走k-1步，然后i、j一起走，当i到达尾节点时，i所指的就是倒数第k个节点。
*/

ListNode* FindKthToTail(ListNode* pHead, int k){
    if(pHead == nullptr || k == 0)
        return nullptr;
    ListNode* pre = pHead;
    ListNode* aft = pHead;
    for(int i = 1; i < k; ++i){
        if(pre->next != nullptr)
            pre = pre->next;
        else
            return nullptr;
    }
    while(pre->next != nullptr){
        pre = pre->next;
        aft = aft->next;
    }
    return aft;
}
