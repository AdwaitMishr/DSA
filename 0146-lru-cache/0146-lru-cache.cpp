class LRUCache {
private:
    struct DLinkedNode {
        int key;
        int value;
        DLinkedNode* pre;
        DLinkedNode* post;
    };

    void addNode(DLinkedNode* node) {
        node->pre = head;
        node->post = head->post;
        head->post->pre = node;
        head->post = node;
    }

    void removeNode(DLinkedNode* node) {
        DLinkedNode* pre = node->pre;
        DLinkedNode* post = node->post;
        pre->post = post;
        post->pre = pre;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addNode(node);
    }

    DLinkedNode* popTail() {
        DLinkedNode* res = tail->pre;
        removeNode(res);
        return res;
    }

  unordered_map<int, DLinkedNode*> cache;
    int count;
    int capacity;
    DLinkedNode* head;
    DLinkedNode* tail;

public:
    LRUCache(int capacity)   {
        count = 0;
        this->capacity = capacity; 
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->post = tail;
        tail->pre = head;
    }

    int get(int key) {
        DLinkedNode* node = cache[key];
        if (node == nullptr) {
            return -1;
        }
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        DLinkedNode* node = cache[key];
        if (node == nullptr) {
            DLinkedNode* newNode = new DLinkedNode();
            newNode->key = key;
            newNode->value = value;
            cache[key] = newNode;
            addNode(newNode);
            ++count;
            if (count > capacity) {
                DLinkedNode* tail = popTail();
                cache.erase(tail->key);
                --count;
            }
        } else {
            node->value = value;
            moveToHead(node);
        }
    }
};
