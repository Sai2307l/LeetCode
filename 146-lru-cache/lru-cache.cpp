
class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key=k;
            val=v;
            prev=next=NULL;
        }
};

class LRUCache {
    public:
        int limit;
        unordered_map<int, Node*> m;
        Node* head;
        Node* tail;

        LRUCache(int capacity){
            limit=capacity;
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
    }


        void addNode(Node* newNode){
            //inserts at head->next
            Node * oldNext = head->next;
            head->next = newNode;
            newNode->prev=head;
            newNode->next=oldNext;
            oldNext->prev=newNode;
        }


        void delNode(Node* node){
            Node* oldPrev = node->prev;
            Node* oldNext = node->next;
            oldPrev->next = oldNext;
            oldNext->prev = oldPrev;
        }
    
        int get(int key) {
            if(m.find(key) == m.end()){
                return -1;
            }

            Node* ansNode = m[key];
            int ans = ansNode->val;
            delNode(ansNode);
            addNode(ansNode);
            return ans;
        }
    
        void put(int key, int val) {
            if(m.find(key) != m.end()){
                Node* oldNode = m[key];
                delNode(oldNode);
                m.erase(key);
            }

            if(m.size() == limit){
                Node * oldNode = tail->prev;
                m.erase(oldNode->key);
                delNode(oldNode);
            }

            Node* newNode = new Node(key,val);
            addNode(newNode);
            m[key]=newNode;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */