class Solution {
private:
    void rec(vector<int>&v, vector<vector<int>>&a, int idx){
        if(idx==v.size()){
            a.push_back(v); return;
        }else{
            for(int i=idx; i<v.size(); i++){
                swap(v[i], v[idx]);
                rec(v,a,idx+1);
                swap(v[i], v[idx]);
            }
        }
        return;
    }
public:    
    vector<vector<int>> permute(vector<int>&v) {
        vector<vector<int>> a;
        rec(v,a,0); return a;
    }
};