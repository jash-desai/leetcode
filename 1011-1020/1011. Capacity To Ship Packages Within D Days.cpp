class Solution {
private:
    bool fxn(vector<int>&v, int&m, int &k){
        int c = 0; int d = 1;
        for(int x : v){
            if(c+x <= m) c += x;
            else c = x, d++;
        }
        return (d<=k);
    }
public:
    int shipWithinDays(vector<int>&v, int k) {
        int l = *max_element(begin(v), end(v));
        int r = 0; for(int x : v) r += x;
        int ans = 0, m = 0;
        while(l<=r){
            m = l + ((r-l) >> 1);
            if(fxn(v,m,k)) ans = m, r = m-1;
            else l = m+1;
        }
        return ans;
    }
};