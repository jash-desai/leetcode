class Solution {
private:
    bool fxn(vector<int>&v, int&m, int&k){
        int cnt = 0;
        for(int i=1; i<size(v); i++){
            if(v[i]-v[i-1] <= m) cnt++, i++;
            else continue;
        } return (cnt>=k);
    }
public:
    int minimizeMax(vector<int>&v, int k) {
        if(k==0) return 0;
        sort(begin(v), end(v)); int n = v.size();
        int l = INT_MAX, r = v[n-1]-v[0], m, ans;
        for(int i=1; i<n; i++) l = min(l, v[i]-v[i-1]);
        while(l<=r){
            m = l + ((r-l) >> 1);
            if(fxn(v,m,k)){
                ans = m; r = m-1;
            }else l = m+1;
        }
        return ans;
    }
};