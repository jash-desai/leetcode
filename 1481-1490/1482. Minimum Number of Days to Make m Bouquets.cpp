class Solution {
private:
    bool fxn(vector<int>&v, int&m, int&n, int&k){
        int curr{0}, cnt{0}, i{0}, t{0};
        for(int i{0}; i<size(v); i++) {
            if(v[i] <= m) curr++;
            else{
                cnt += (curr/k);
                curr = 0;
            }
        }
        cnt += (curr/k);
        return (cnt >= n);
    }
public:
    int minDays(vector<int> &v, int n, int k) {
        if(size(v)/k < n) return -1;
        int l = *min_element(begin(v), end(v));
        int r = *max_element(begin(v), end(v));
        int m, ans;
        while(l<=r){
            m = (l + ((r-l) >> 1));
            if(fxn(v,m,n,k)){
                ans = m;
                r = m-1;
            }else l = m+1;
        }
        return ans;
    }
};