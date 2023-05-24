class Solution {
public:
    using pii = pair<int, int>;
    long long maxScore(vector<int>&a, vector<int>&b, int k) {
        int n=a.size(); vector<pii> p(n);
        for(int i=0; i<n; i++) p[i]={b[i],a[i]};
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(p.begin(),p.end(), [](pii&x, pii&y){
            if(x.first==y.first) return x.second<y.second;
            return x.first<y.first;
        });
        long long  ans = 0, sum = 0;
        for(int i = n-1; i >= 0; i--){
            auto &[x,y] = p[i];
            sum += y; pq.push(y);
            if(i < n-k+1){     
                if(pq.size()>k){
                    sum -= pq.top();
                    pq.pop();
                }
                ans = max(ans,sum*x);
            }
        }
        return ans;
    }
};