class LRUCache {
    struct Node{
        int key,value;
        Node* next, *prev;
        Node(int k,int v): key(k),value(v),next(nullptr),prev(nullptr) {};
        Node(int k,int v, Node* nxt, Node* pre): key(k),value(v),next(nxt),prev(pre) {};
    };
    map<int,Node*> lookup;
    Node *head,*tail;
    int cap,size=0;
public:
    LRUCache(int capacity): cap(capacity),head(new Node(-1,-1)),tail(new Node(-1,-1)) {
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* insertFront(int key,int value){
        Node* node = new Node(key,value,head->next,head);
        head->next= node;
        node->next->prev = node;
        return node;
    }

    int get(int key) {
        if(lookup.find(key)!=lookup.end()){
            Node* node = lookup[key];
            int val = node->value;
            deleteNode(node);
            lookup[key] = insertFront(key,val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lookup.find(key)!=lookup.end()){
            Node* node = lookup[key];
            deleteNode(node);
            lookup[key] = insertFront(key,value);
        }else{
            if(size==cap){
                lookup.erase(tail->prev->key);
                deleteNode(tail->prev);
                lookup[key] = insertFront(key,value);
            }else{
                size++;
                lookup[key] = insertFront(key,value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */