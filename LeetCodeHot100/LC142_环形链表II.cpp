/*
    难度：中等

    题目：给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回null。

    思路：快慢指针确定有环后，再定义一个指针指向头节点，然后慢指针和新指针一起移动，
         两指针相遇时，即为环的入口。
*/

ListNode *detectCycle(ListNode *head){
    if(head == nullptr)
        return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    do{
        if(fast == nullptr || fast->next == nullptr)
            return nullptr;
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    ListNode* ptr = head;
    while(slow != ptr){
        slow = slow->next;
        ptr = ptr->next;
    }
    return ptr;
}



/*
下面的程序是错误的。
错误的原因是slow和fast的初始化方式，在LC141，我们确定有没有环的时候，这样初始化没问题。
因为那会儿我们不关心slow和fast的相遇点，只关心slow和fast是否相遇。

而找环的入口，我发现slow和fast的相遇点会影响ptr和slow的相遇，按照下边这种写法，
[3,2,0,-4](1),这个环形链表，slow和ptr就永远遇不到。所以也就找不出环入口。
*/
ListNode *detectCycle(ListNode *head){
    if(head == nullptr)
        return nullptr;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(slow != fast){
        if(fast == nullptr || fast->next == nullptr)
            return nullptr;
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* ptr = head;
    while(slow != ptr){
        slow = slow->next;
        ptr = ptr->next;
    }
    return ptr;
}