class LRUCache {
public:
    class node{
        public: 
        int key; 
        int val; 
        node* next; 
        node* prev; 
        node(int key, int val)
        {
            this->key = key; 
            this->val = val; 
        }
    }; 
    
    int capacity = 0; 
    unordered_map<int, node*> mp; 
    
    node* head = new node(-1, -1); 
    node* tail = new node(-1, -1); 
    
    LRUCache(int capacity) {
        
        this->capacity = capacity; 
        head->next = tail; 
        tail->prev = head; 
    }
    
    void addNode(node* newnode)
    {
        node* temp = head->next; 
        head->next = newnode; 
        newnode->prev = head; 
        newnode->next = temp; 
        temp->prev = newnode; 
    }
    
    void deleteNode(node* delnode)
    {
        node* delprev = delnode->prev; 
        node* delnext = delnode->next; 
        delprev->next = delnext; 
        delnext->prev = delprev; 
    }

    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            node* resnode = mp[key]; 
            int res = resnode->val; 
            deleteNode(resnode); 
            addNode(resnode); 
            mp[key] = head->next; 
            return res; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            node* existingNode = mp[key]; 
            mp.erase(key);
            deleteNode(existingNode); 
        }
        
        if(capacity == mp.size())
        {
            mp.erase(tail->prev->key); 
            deleteNode(tail->prev); 
        }
        
        addNode(new node(key, value)); 
        mp[key] = head->next; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */