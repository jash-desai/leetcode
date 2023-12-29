class Solution {
private:
    bool fxn(vector<int>&v, int m, int k){
        long long int cnt = 0;
        for(int &x : v) cnt += (x-1)/m + 1;
        return (cnt<=k);
    }
public:
    int minEatingSpeed(vector<int>&v, int k){
        int n = size(v); int m, ans;
        int l = 1;
        int r = *max_element(begin(v), end(v));
        while(l<=r){
            m = (l + ((r-l) >> 1));
            if(fxn(v,m,k)){
                ans = m;
                r = m-1;
            }else l = m+1;
        }
        return ans;
    }
};