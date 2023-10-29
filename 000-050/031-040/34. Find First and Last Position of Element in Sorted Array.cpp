class Solution {
private:
    int first(vector<int>&v, int k){
        int n = v.size(), l = 0, r = n-1, ans = n;
        while(l<=r){
            int m = (l + ((r-l) >> 1));
            if(v[m]==k) ans = m, r = m-1;
            else if(v[m]<k) l = m+1;
            else r = m-1;
        }
        return (ans==n) ? -1 : ans;
    }
    int last(vector<int>&v, int k){
        int n = v.size(), l = 0, r = n-1, ans = -1;
        while(l<=r){
            int m = (l + ((r-l) >> 1));
            if(v[m]==k) ans = m, l = m+1;
            else if(v[m]<k) l = m+1;
            else r = m-1;
        }
        return (ans==-1) ? -1 : ans;
    }
public:
    vector<int> searchRange(vector<int>&v, int k) {
        int n = v.size(), fp = first(v,k), lp = last(v,k);
        return {fp, lp};
    }
};