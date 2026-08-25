class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value){
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void add(Node* node){
        Node* last = tail->prev;

        last->next = node;
        node->prev = last;

        node->next = tail;
        tail->prev = node;
    }
    void remove(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node = mp[key];
        remove(node);
        add(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            remove(node);
            node->value = value;
            add(node);
        }
        else{
            Node* node = new Node(key, value);
            mp[key] = node;
            add(node);
        }
        if(mp.size()>capacity){
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */