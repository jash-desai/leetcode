class Solution {
private:
    bool fx(string&a, string&b){
        int n = a.size(), m = b.size();
        if(n-m != 1) return 0;
        int i=0, j=0; int c = 0;
        while(i<n){
            if(j<m and a[i]==b[j]){
                i++, j++;
            }else{
                if(c==1) return 0;
                i++, c++;
            }
        }
        return (i==n and j==m);
    }
    
public:
    int longestStrChain(vector<string>&v) {
        int n = v.size(), ans = 1; vector<int> dp(n, 1);
        sort(v.begin(), v.end(), [](string&a, string&b){
            return a.size() < b.size();
        });
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(fx(v[i], v[j]) and 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};