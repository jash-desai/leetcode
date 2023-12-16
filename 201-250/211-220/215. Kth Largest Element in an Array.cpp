class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int &x : v){
            pq.push(x);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

// what is quickselect ???? 