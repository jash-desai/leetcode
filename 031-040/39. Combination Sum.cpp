class Solution {
public:
    void rec(vector<int>&v, vector<vector<int>>&a, vector<int>&t, int k, int idx){
        if(!k) a.push_back(t);
        if(idx==v.size()) return;
        while(idx<v.size() && k-v[idx]>=0){
            t.push_back(v[idx]);
            rec(v,a,t,k-v[idx],idx);
            idx++;
            t.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>&v, int k) {
        vector<vector<int>> a;
        vector<int> t;
        sort(v.begin(), v.end());
        set<int> s(v.begin(), v.end());
        v.assign(s.begin(), s.end());
        rec(v,a,t,k,0);
        return a;
    }
};