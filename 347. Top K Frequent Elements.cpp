#define pii pair<int,int>
class Solution {
private:
    struct cmp{
        bool operator()(pii p1, pii p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        map<int,int> m;
        for(int x:v) m[x]++;
        priority_queue<pii, vector<pii>, cmp> pq(m.begin(), m.end());
        vector<int> ans(k); int i=0;
        while(i<k){
            ans[i++] = (pq.top()).first;
            pq.pop();
        }
        return ans;
    }
};