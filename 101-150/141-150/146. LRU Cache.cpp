class Node{
public:
    int key; int val;
    Node* next; Node* prev;
    Node(int k, int v){
        this->key = k; this->val = v;
        next = NULL; prev = NULL;
    }
};
class LRUCache {
private:
    int cap; unordered_map<int, Node*> m;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
public:
    LRUCache(int n) {
        cap = n;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node; temp->prev = node;
        node->next = temp; node->prev = head;
    }
    void delNode(Node* node){
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int k) {
        if(m.find(k) != m.end()){
            Node* node = m[k];
            int ans = node->val;
            m.erase(k); delNode(node);
            addNode(node); m[k] = head->next;
            return ans;
        }
        return -1;
    }
    void put(int k, int val){
        if(m.find(k) != m.end()){
            Node* node = m[k];
            m.erase(k); delNode(node);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            delNode(tail->prev); 
        }
        addNode(new Node(k, val));
        m[k] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */