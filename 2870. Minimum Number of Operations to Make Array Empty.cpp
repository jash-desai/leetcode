class Solution {
public:
    int minOperations(vector<int>&v) {
        int n = v.size();
        map<int, int> mp; int ans = 0;
        for(int i=0; i<n; i++) mp[v[i]]++;
        for(auto &x : mp){
            int i = x.first, cnt = x.second;
            if(cnt==1) return -1;
            if(cnt%3){
                ans++;
            }
            ans += cnt/3;
        }
        return ans;
    }
};