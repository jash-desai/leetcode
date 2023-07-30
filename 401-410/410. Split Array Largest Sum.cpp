class Solution {
private:
    bool fxn(vector<int>&v, int &m, int &k){
        int curr = 0, cnt = 1;
        for(int x : v){
            if(x + curr <= m) curr += x;
            else curr = x, cnt++;
        }
        return (cnt<=k);
    }
public:
    int splitArray(vector<int>& v, int k) {
        if(k>size(v)) return -1;
        int l = *max_element(begin(v), end(v));
        int r = 0; for(int &x : v) r += x;
        int m, ans;
        while(l<=r){
            m = l + ((r-l) >> 1);
            if(fxn(v,m,k)) ans = m, r = m-1;
            else l = m+1;
        }
        return ans;
    }
};