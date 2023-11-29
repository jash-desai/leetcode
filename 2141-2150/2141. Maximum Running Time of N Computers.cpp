class Solution {
private:
    bool fxn(vector<int>&v, long long&m, int&k){
        long long cnt{0};
        for(int x : v) cnt += min(m, 1LL*x);
        return (cnt >= (m*k));
    }
public:
    long long maxRunTime(int k, vector<int>&v) {
        long long l{1}, r = 0; for(int &x : v) r += x;
        r /= k; long long ans{0}, m;
        while(l <= r){
            m = (l + ((r-l) >> 1));
            if(fxn(v,m,k)) ans = m, l = m + 1; 
            else r = m - 1;
        }
        return ans;
    }
};