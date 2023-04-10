class Solution {
public:
    void rec(vector<int>&v, vector<vector<int>>&a, vector<int>&t, int idx){
        a.push_back(t);
        for(int i=idx; i<v.size(); i++){
            if(i!=idx and v[i]==v[i-1]) continue;
            t.push_back(v[i]);
            rec(v,a,t,i+1);
            t.erase(t.end()-1);
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>&v) {
        vector<vector<int>> a;
        vector<int> t;
        sort(v.begin(), v.end());
        rec(v,a,t,0);
        return a;
    }
};