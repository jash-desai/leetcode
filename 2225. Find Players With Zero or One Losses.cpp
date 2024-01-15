class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
        vector<vector<int>> ans(2);
        map<int, pair<int,int>> mp;
        for(auto x : v){
            int w = x[0];
            int l = x[1];
            mp[w].first++;
            mp[l].second++;
        }
        for(auto &[x, p] : mp){
            int wins = p.first, loss = p.second;
            if(loss==0) ans[0].push_back(x);
            if(loss==1) ans[1].push_back(x);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};