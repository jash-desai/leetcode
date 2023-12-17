#define prq priority_queue
#define pii pair<int,int>
#define pip pair<int,pii>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>&a, vector<int>&b, int k) {
        vector<vector<int>> ans; int n = a.size(), m = b.size();
        prq<pii, vector<pii>, greater<pii>> pq;
        /* O(N^2)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pq.push({a[i]+b[j], {a[i],b[j]}});
            }
        }
        */
        for(int x : a) pq.push({x+b[0], 0});
        while(k-- and !pq.empty()){
            int val = pq.top().first, idx = pq.top().second;
            pq.pop(); ans.push_back({val-b[idx], b[idx]});
            if(idx+1 < m){
                pq.push({val-b[idx]+b[idx+1], idx+1});
            }
        }
        return ans;
    }
};