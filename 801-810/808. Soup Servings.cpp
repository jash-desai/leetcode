class Solution {
    double dp[195][195];
private:
    double f(int a, int b) {
        if (a <= 0 and b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (dp[a][b] > 0) return dp[a][b];
        dp[a][b] = (0.25)*(f(a-4,b) + f(a-3,b-1) + f(a-2,b-2) + f(a-1,b-3));
        return dp[a][b];
    }
public:
    double soupServings(int n) {
        return n > 4800 ?  1.0 : f((n + 24)/25, (n+24)/25);
    }
};