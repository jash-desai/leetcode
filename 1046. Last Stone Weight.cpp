class Solution {
public:
    int lastStoneWeight(vector<int>& v){
        priority_queue<int, vector<int>> pq;
        for(int i=0; i<v.size(); i++) {             
            pq.push(v[i]); 
        }
        int x, y;
        while(pq.size()>1){
            y = pq.top(); pq.pop();
            x = pq.top(); pq.pop();
            if(x!=y){
                pq.push(y-x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};