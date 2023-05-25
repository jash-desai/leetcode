class Solution {
  public:
  double new21Game(int n, int k, int maxPts) {
    if (k==0 or n >= k-1 + maxPts) return 1.0;
    double ans = 0.0; vector<double> dp(n + 1);
    dp[0] = 1.0; double windowSum = dp[0];
    for (int i=1; i<=n; i++){
      dp[i] = windowSum / maxPts;
      if (i<k) windowSum += dp[i];
      else ans += dp[i];
      if(i - maxPts >= 0) windowSum -= dp[i - maxPts];
    }
    return ans;
  }
};