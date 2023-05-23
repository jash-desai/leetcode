class KthLargest {
public:
    KthLargest(int k, vector<int>& v) {
        K = k;
        for(int i=0;i<v.size();i++) pq.push(v[i]);
        while(pq.size() > k) pq.pop();
    }
    int add(int val) {
        pq.push(val);
        if(pq.size() > K)  pq.pop();
        return pq.top();
    }
    priority_queue<int, vector<int>, greater<int>>pq;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */