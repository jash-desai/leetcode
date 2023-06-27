#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ios1 std::ios::sync_with_stdio(0);
#define ios2 cin.tie(NULL);cout.tie(NULL);return 0;
static int opt = [](){ios1; ios2}();

class Solution {
    int n, k;
private:
    int rec(vi&v, int i, bool f, vvi&dp){
        if(i==n) return 0;
        if(dp[i][f] != -1) return dp[i][f];
        int ans1, ans2;
        if(f){
            ans1 = -v[i] + rec(v,i+1,0,dp);
            ans2 = rec(v,i+1,1,dp);
        }else{
            ans1 = v[i] - k + rec(v,i+1,1,dp);
            ans2 = rec(v,i+1,0,dp);
        }
        return dp[i][f] = max(ans1,ans2);
    }
public:
    int maxProfit(vector<int>&v, int K){
        n = v.size(), k = K;
        /*
        vvi dp(n+1, vi(2, 0));
        // return rec(v,0,1,dp);
        for(int i=n-1; i>=0; i--){
            for(int f=0; f<=1; f++){
                int ans1, ans2;
                if(f){
                    ans1 = -v[i] + dp[i+1][0];
                    ans2 = dp[i+1][1];
                }else{
                    ans1 = v[i] - k + dp[i+1][1];
                    ans2 = dp[i+1][0];
                }
                dp[i][f] = max(ans1,ans2);
            }
        }
        return dp[0][1];
        */
        vi prev(2,0), curr(2,0);
        for(int i=n-1; i>=0; i--){
            for(int f=0; f<=1; f++){
                int ans1, ans2;
                if(f){
                    ans1 = -v[i] + prev[0];
                    ans2 = prev[1];
                }else{
                    ans1 = v[i] - k + prev[1];
                    ans2 = prev[0];
                }
                curr[f] = max(ans1,ans2);
            }
            prev = curr;
        }
        return prev[1];
    }
};