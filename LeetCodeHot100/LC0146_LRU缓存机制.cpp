/*
    题目：
        运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
        实现 LRUCache 类：
            LRUCache(int capacity) ：
                以正整数作为容量 capacity 初始化 LRU 缓存
            int get(int key) ：
                如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
            void put(int key, int value)：
                如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。
                当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
    思路：
        LRU 缓存机制可以通过哈希表辅以双向链表实现，我们用一个哈希表和一个双向链表维护所有在缓存中的键值对。
            双向链表按照被使用的顺序存储了这些键值对，靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的。
            哈希表即为普通的哈希映射（HashMap），通过缓存数据的键映射到其在双向链表中的位置。
*/
struct DListNode{
    int key;
    int value;
    DListNode* next;
    DListNode* prev;
    DListNode() : key(0), value(0), next(nullptr), prev(nullptr) {}
    DListNode(int _key, int _value) : key(_key), value(_value), next(nullptr), prev(nullptr) {}
};

class LRUCache{
public:
    LRUCache(int _capacity) : capacity(_capacity), used(0) {
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(!cache.count(key)){
            return -1;
        }
        DListNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value){
        if(!cache.count(key)){
            DListNode* node = new DListNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++used;
            if(used > capacity){
                DListNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                removed = nullptr;
                --used;
            }
        }
        else{
            DListNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

private:
    int capacity;
    int used;
    std::unordered_map<int, DListNode*> cache;
    DListNode* head;
    DListNode* tail;

    void addToHead(DListNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DListNode* node){
        removeNode(node);
        addToHead(node);
    }

    DListNode* removeTail(){
        DListNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};