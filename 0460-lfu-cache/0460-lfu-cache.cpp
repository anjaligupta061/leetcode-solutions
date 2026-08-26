struct Node{
    int key;
    int value;
    int cnt;
    Node* next;
    Node* prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;

        size=0;
    }

    //add node at the front
    void addFront(Node* node){
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    // Remove a node from the list
    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }
};
class LFUCache {
public:
    //key->node
    map<int, Node*> keyNode;

    //frequency->DLL
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;
    LFUCache(int capacity) {
        maxSizeCache = capacity;

        minFreq = 0;
        currSize = 0;
    }
    
    void updateFreqListMap(Node* node){
        // Remove node from key map temporarily
        keyNode.erase(node->key);
        // Current frequency
        int currFreq = node->cnt;
        // Remove node from current frequency list
        freqListMap[currFreq]->removeNode(node);
        // If current frequency was minimum
        // and its list became empty,
        // minimum frequency increases
        if(currFreq == minFreq && freqListMap[currFreq]->size==0){
            minFreq++;
        }
        // Move node to next frequency
        node->cnt++;

        List* nextHigherFreqList;

        // If frequency list already exists
        if(freqListMap.find(node->cnt)!=freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt];
        }
        // Otherwise create a new list
        else{
            nextHigherFreqList = new List();
        }

        // Add node at front
        nextHigherFreqList->addFront(node);

        // Save list
        freqListMap[node->cnt] = nextHigherFreqList;

        // Add node back to key map
        keyNode[node->key] = node;
    }
    int get(int key) {
        // Key doesn't exist
        if(keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        int value = node->value;
        // Accessing a node increases its frequency
        updateFreqListMap(node);
        return value;
    }
    
    void put(int key, int value) {
        // Capacity is zero
        if(maxSizeCache == 0) {
            return;
        }

        // Key already exists
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];

            // Update value
            node->value = value;

            // Frequency increases
            updateFreqListMap(node);

            return;
        }

        // Cache is full
        if(currSize == maxSizeCache){
            // Get list corresponding to minimum frequency
            List* list = freqListMap[minFreq];
            // Remove least recently used node
            // from this frequency
            Node* remove = list->tail->prev;
            keyNode.erase(remove->key);
            list->removeNode(remove);
            currSize--;
        }
        // New node
        Node* node = new Node(key, value);

        // New node always has frequency 1
        minFreq = 1;

        List* listFreq;
        // Frequency 1 list already exists
        if(freqListMap.find(1)!=freqListMap.end()){
            listFreq = freqListMap[1];
        }
        // Otherwise create it
        else {
            listFreq = new List();
        }
        // Add new node at front
        listFreq->addFront(node);
        // Store frequency list
        freqListMap[1] = listFreq;
        // Store key -> node
        keyNode[key] = node;
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */