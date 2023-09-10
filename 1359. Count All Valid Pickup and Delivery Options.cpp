class Solution {
    const int mod = 1e9+7;
public:
    int countOrders(int n) {
        if(n==1) return n;
        long long int ans = 1;
        for(int i{2}; i<=n; i++){
            ans = (ans*((2*i)-1)*i)%mod;
        } return ans;
    }
};