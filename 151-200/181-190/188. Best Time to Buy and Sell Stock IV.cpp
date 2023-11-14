#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ios std::ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);return 0;
static int opt = [](){ios}();

class Solution {
    int n, K;
private:
    /* O(N*K*2);
    int rec(vector<int>&v, int i, int k, bool f, vvvi&dp){
        if(i==n or k==0) return 0;
        if(dp[i][k][f] != -1) return dp[i][k][f];
        int ans1, ans2;
        if(f){
            ans1 = -v[i] + rec(v,i+1,k,0,dp);
            ans2 = rec(v,i+1,k,1,dp);
        }else{
            ans1 = v[i] + rec(v,i+1,k-1,1,dp);
            ans2 = rec(v,i+1,k,0,dp);
        }
        return dp[i][k][f] = max(ans1,ans2);
    }
    */
    /* O(N*(2*K));
    int rec(vector<int>&v, int i, int k, vvi&dp){
        if(i==n or k==2*K) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int ans1, ans2;
        if(k%2){
            ans1 = v[i] + rec(v,i+1,k+1,dp);
            ans2 = rec(v,i+1,k,dp);
        }else{
            ans1 = -v[i] + rec(v,i+1,k+1,dp);
            ans2 = rec(v,i+1,k,dp);
        }
        return dp[i][k] = max(ans1,ans2);
    }
    */
public:
    int maxProfit(int t, vector<int>&v) {
        n = v.size(); K = t;
        /*
        vvvi dp(n+1, vvi(t+1, vi(2, 0)));
        // return rec(v,0,t,1,dp);
        for(int i=n-1; i>=0; i--){
            for(int k=1; k<=t; k++){
                for(int f=0; f<=1; f++){
                    int ans1, ans2;
                    if(f){
                        ans1 = -v[i] + dp[i+1][k][0];
                        ans2 = dp[i+1][k][1];
                    }else{
                        ans1 = v[i] + dp[i+1][k-1][1];
                        ans2 = dp[i+1][k][0];
                    }
                    dp[i][k][f] = max(ans1,ans2);
                }
            }
        }
        return dp[0][t][1];
        */
        /*
        vvi prev(t+1, vi(2, 0)), curr(t+1, vi(2, 0));
        for(int i=n-1; i>=0; i--){
            for(int k=1; k<=t; k++){
                for(int f=0; f<=1; f++){
                    int ans1, ans2;
                    if(f){
                        ans1 = -v[i] + prev[k][0];
                        ans2 = prev[k][1];
                    }else{
                        ans1 = v[i] + prev[k-1][1];
                        ans2 = prev[k][0];
                    }
                    curr[k][f] = max(ans1,ans2);
                }
            }
            prev = curr;
        }
        return prev[t][1];
        */
        /*
        vvi dp(n+1, vi((2*K)+1, 0));
        // return rec(v,0,0,dp);
        for(int i=n-1; i>=0; i--){
            for(int k=((2*K)-1); k>=0; k--){
                int ans1, ans2;
                if(k%2){
                    ans1 = v[i] + dp[i+1][k+1];
                    ans2 = dp[i+1][k];
                }else{
                    ans1 = -v[i] + dp[i+1][k+1];
                    ans2 = dp[i+1][k];
                }
                dp[i][k] = max(ans1,ans2);
            }
        }
        return dp[0][0];
        */
        vi prev((2*K)+1, 0), curr((2*K)+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int k=((2*K)-1); k>=0; k--){
                int ans1, ans2;
                if(k%2){
                    ans1 = v[i] + prev[k+1];
                    ans2 = prev[k];
                }else{
                    ans1 = -v[i] + prev[k+1];
                    ans2 = prev[k];
                }
                curr[k] = max(ans1,ans2);
            }
            prev = curr;
        }
        return prev[0];
    }   
};