class Solution {
    const unsigned MOD = 1'000'000'007;
public:
    int numMusicPlaylists(int n, int goal, int k) {
        long dp[1+goal][1+n]; memset( dp, 0, sizeof dp); dp[0][0] = 1;
        for( int i = 1; i <= goal; ++i )
            for( int j = 1; j <= n; ++j ) {
                dp[i][j] = dp[i-1][j-1] * ( n - (j-1) );
                dp[i][j] += dp[i-1][j] * max( j-k, 0 );
                dp[i][j] %= MOD;
            }
        return dp[goal][n];
    }
};