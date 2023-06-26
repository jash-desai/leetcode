#define prq priority_queue
class Solution{
public:
    long long totalCost(vector<int>&v, int k, int c) {
        int n=v.size(), i=0, j=n-1; long long ans = 0;
        prq<int, vector<int>, greater<int>> pq1;
        prq<int, vector<int>, greater<int>> pq2;
        while(k--){
            while(pq1.size() < c and i <= j) pq1.push(v[i++]);
            while(pq2.size() < c and i <= j) pq2.push(v[j--]);
            int val1 = pq1.size() > 0 ? pq1.top() : INT_MAX; 
            int val2 = pq2.size() > 0 ? pq2.top() : INT_MAX; 
            
            if(val1<=val2){
                ans += val1; pq1.pop();
            }else{
                ans += val2; pq2.pop();
            }            
        }
        return ans;
    }
};