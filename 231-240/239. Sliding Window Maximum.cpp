#define pii pair<int, int>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size(); priority_queue<pii> pq;
        vector<int> ans(n-k+1);
        for(int i=0; i<k; i++) pq.push({v[i], i});
        ans[0] = pq.top().first;
        for(int i=k; i<n; i++){
            while(!pq.empty() and pq.top().second <= (i-k)) pq.pop();
            pq.push({v[i], i});
            ans[i-k+1] = pq.top().first;
        }
        return ans;
    }
};