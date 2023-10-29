#define all(v) v.begin(),v.end()
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&v){
        int n = v.size(); vector<vector<int>> ans;
        sort(all(v)); ans.push_back(v[0]);
        for(int i=1; i<n; i++){
           vector<int>&x = ans.back();
            if(x[1] >= v[i][0]) x[1] = max(x[1], v[i][1]);
            else ans.push_back(v[i]);
        }
        return ans;
    }
};