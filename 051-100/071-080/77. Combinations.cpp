class Solution {
private:
    void rec(int i, int n, int k, vector<vector<int>>&v, vector<int>&t){
        if(i==n+1){
            if(t.size()==k) v.push_back(t);
            return;
        }
        t.push_back(i); rec(i+1,n,k,v,t);
        t.pop_back(); rec(i+1,n,k,v,t);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v;
        vector<int> t;
        rec(1,n,k,v,t); return v;
    }
};