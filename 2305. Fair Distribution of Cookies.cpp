class Solution {
public:
    int ans = INT_MAX; int n;
    void solve(int idx, vector<int>&v, vector<int>&temp, int k){
        if(idx == n){
            int maxm = INT_MIN;
            for(int i=0; i<k; i++){
                maxm = max(maxm,temp[i]);
            }
            ans = min(ans,maxm);
            return;
        }
        for(int i=0; i<k; i++){
            temp[i] += v[idx];
            solve(idx+1,v,temp,k);
            temp[i] -= v[idx];
        }
    }
    
    int distributeCookies(vector<int>& v, int k) {
        n = v.size(); vector<int> temp(k,0);
        solve(0,v,temp,k);
        return ans;
    }
};