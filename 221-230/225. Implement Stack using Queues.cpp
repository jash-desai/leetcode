class MyStack {
    queue<int> qa, qb;
public:
    MyStack() {
        
    }
    
    void push(int k) {
        qa.push(k);
        while(qb.size()){
            qa.push(qb.front()); qb.pop();
        }
        swap(qa, qb);
    }
    
    int pop() {
        int k = qb.front(); qb.pop();
        return k;
    }
    
    int top() {
        return qb.front();
    }
    
    bool empty() {
        return (qb.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */