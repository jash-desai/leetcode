#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ios std::ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);return 0;
static int opt = [](){ios}();

class Solution {
    int n;
private:
    /* N*3*2 -->
    int rec(vector<int>&v, int i, int k, bool f, vvvi&dp){
        if(i==n or k==0) return 0;
        if(dp[i][k][f] != -1) return dp[i][k][f];
        int ans1, ans2;
        if(f){
            ans1 = -v[i] + rec(v,i+1,k,false,dp);
            ans2 = rec(v,i+1,k,true,dp);
            return dp[i][k][f] = max(ans1,ans2);
        }else{
            ans1 = v[i] + rec(v,i+1,k-1,true,dp);
            ans2 = rec(v,i+1,k,false,dp);
            return dp[i][k][f] = max(ans1,ans2);
        }
    }
    */
    /* N*4 -->
    int rec(vector<int>&v, int i, int k, vvi&dp){
        if(i==n or k==4) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int ans1, ans2;
        if(k%2){
            ans1 = v[i] + rec(v,i+1,k+1,dp);
            ans2 = rec(v,i+1,k,dp);
            return dp[i][k] = max(ans1,ans2);
        }else{
            ans1 = -v[i] + rec(v,i+1,k+1,dp);
            ans2 = rec(v,i+1,k,dp);
            return dp[i][k] = max(ans1,ans2);
        }
    }
    */
public:
    int maxProfit(vector<int>&v) {
        n = v.size();
        /*
        vvvi dp(n+1, vvi(3, vi(2, 0)));
        // return rec(v,0,2,1,dp);
        for(int i=n-1; i>=0; i--){
            for(int k=1; k<=2; k++){
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
        return dp[0][2][1];
        */
        /* O(3*2) SC;
        vvi prev(3, vi(2, 0)), curr(3, vi(2, 0));
        for(int i=n-1; i>=0; i--){
            for(int k=1; k<=2; k++){
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
        return prev[2][1];
        */
        /*
        // O(N*4) SC;
        vvi dp(n+1, vi(5, 0));
        // return rec(v,0,0,dp);
        for(int i=n-1; i>=0; i--){
            for(int k=3; k>=0; k--){
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
        vi prev(5, 0), curr(5, 0);
        for(int i=n-1; i>=0; i--){
            for(int k=3; k>=0; k--){
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