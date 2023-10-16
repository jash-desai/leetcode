class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0) return {1};
        if(n==1) return {1, 1};
        vector<int> ans(n+1);
        int idx = 1; ans[0] = ans[n] = 1;
        for(int i=1; i<=n-1; i++){
            long long int k = ((ans[i-1])*1LL*(n-i+1));
            // cout << k << " ";
            k /= i; ans[idx] = k; idx++;
        }
        return ans;
    }
};