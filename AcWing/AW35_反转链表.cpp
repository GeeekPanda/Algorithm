/*
    题目:
        定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
        思考题：
            请同时实现迭代版本和递归版本。
        样例
            输入:1->2->3->4->5->NULL
            输出:5->4->3->2->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//迭代版本
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp; 
        }
        return prev;
    }
};

//递归版本
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};