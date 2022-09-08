class Solution {
public:
    void rec(vector<int>&v, vector<vector<int>>&a, vector<int>&t, int k, int idx){
        if(!k){
            a.push_back(t);
            return;
        }
        for(int i=idx; i<v.size(); i++){
            if(i>idx && v[i]==v[i-1]) continue;
            if(v[i]>k) break;
            t.push_back(v[i]);
            rec(v,a,t,k-v[i],i+1);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>&v, int k) {
        sort(v.begin(), v.end());
        vector<vector<int>> a;
        vector<int> t;
        rec(v,a,t,k,0);
        // set<vector<int>> s(a.begin(), a.end());
        // a.assign(s.begin(), s.end());
        return a;
    }
};