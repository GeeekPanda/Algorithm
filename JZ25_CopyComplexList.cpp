/*
    题目：
        输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），
        请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）。
    思路：
        分三步完成：
        1. 复制每一个节点，并把新节点放在原节点后边。
           如A->B->C->D->E,复制后，A->A'->B->B'->C->C'->D->D'->E->E'。
        2. 复制每个节点的random指针给新的节点。
           如果D的random指向B，那么B'是B->next指向的节点，D'是D->next指向的节点。
           D'->random = D->random->next;就设置好了D'的random指向B'。
        3. 将长链表拆分为两个链表。
           奇数位置的节点用next连起来就是原始链表；
           偶数位置的节点用next连起来就是复制出来的新链表。

*/



/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

/*
    if (oriNode->random == nullptr){
        if(curNode->next)
            curNode = curNode->next->next;
        oriNode = oriNode->next->next;
        continue;
    }
    curNode->random = oriNode->random->next;
    if (curNode->next)
        curNode = curNode->next->next;
    oriNode = oriNode->next->next;
*/
RandomListNode* Clone(RandomListNode* pHead){
    if(pHead == nullptr)
        return nullptr;
    //复制节点，并连接在旧节点的后边
    RandomListNode* oriNode = pHead;
    while(oriNode){
        RandomListNode* newNode = new RandomListNode(oriNode->label);
        newNode->next = oriNode->next;
        oriNode->next = newNode;
        oriNode = oriNode->next->next;
    }
    //复制random指针
    oriNode = pHead;
    RandomListNode* curNode = pHead->next;
    while(oriNode && curNode){
        if(oriNode->random)
            curNode->random = oriNode->random->next;
        if (curNode->next)
            curNode = curNode->next->next;
        oriNode = oriNode->next->next;
    }
    //拆分链表
    oriNode = pHead;
    curNode = pHead->next;
    RandomListNode* newHead = curNode;
    while(oriNode && curNode){
        oriNode->next = curNode->next;
        oriNode = curNode->next;
        if(curNode->next)
            curNode->next = oriNode->next;
        curNode = oriNode->next;
    }
    return newHead;
}