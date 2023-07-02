#define all(x) begin(x),end(x)
#define maxele max_element
class Solution {
public:
    int ans = INT_MAX; int n; int k;
    void solve(int idx, vector<int>&v, vector<int>&temp){
        if(idx == n){
            int maxm = *maxele(all(temp));
            ans = min(ans,maxm);
            return;
        }
        for(int i=0; i<k; i++){
            temp[i] += v[idx];
            solve(idx+1,v,temp);
            temp[i] -= v[idx];
            if(v[i]==0) break;
        }
    }
    
    int distributeCookies(vector<int>& v, int K) {
        n = size(v); k = K; vector<int> temp(k,0);
        solve(0,v,temp);
        return ans;
    }
};