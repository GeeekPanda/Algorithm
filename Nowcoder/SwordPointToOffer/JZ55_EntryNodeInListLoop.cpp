class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(!pHead || !pHead->next)
            return nullptr;
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        
        ListNode* find = pHead;
        while(find != slow){
            find = find->next;
            slow = slow->next;
        }
        return find;
    }
};