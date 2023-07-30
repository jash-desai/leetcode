class Solution {
public:
    int dp[1001][11];
    int solve(vector<int>& jb, int d , int i){
        if(d==1){
            return *max_element(jb.begin()+i , jb.end());
        }
        
        if(dp[i][d] != -1){
            return dp[i][d];
        }
        
        int mx = INT_MIN;
        int mn =INT_MAX;
        for(int j=i ; j<=jb.size()-d ; j++){
            mx = max(jb[j] , mx);
            mn = min(mn , mx + solve(jb , d-1 , j+1));
            
        }
        
        
       // return  mn; 
        dp[i][d]= mn;
        return dp[i][d];
    }
    
    int minDifficulty(vector<int>& jb, int d) {
        memset(dp , -1, sizeof(dp));
        if(jb.size()<d){
            return -1;
        }
        
        
        return solve(jb, d, 0 );
        
    }
};