class Solution {
private:
    int fp(vector<int>&v, int k){
        int n=v.size();
        int l=0, r=n-1, m;
        while(l<=r){
            m = (l+r)>>1;
            if(v[m]==k and (m==0 or (m!=0 and v[m-1]!=k))) return m;
            if(v[m]==k and v[m-1]==k){
                r=m-1;
            }
            if(v[m]>k) r=m-1;
            else if(v[m]<k) l=m+1;
        }
        return -1;
    }
    int lp(vector<int>&v, int k){
        int n=v.size();
        int l=0, r=n-1, m;
        while(l<=r){
            m = (l+r)>>1;
            if(v[m]==k and (m==n-1 or (m!=n-1 and v[m+1]!=k))) return m;
            if(v[m]==k and v[m+1]==k){
                l=m+1;
            }
            if(v[m]>k) r=m-1;
            else if(v[m]<k) l=m+1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>&v, int k) {
        vector<int> a(2,-1);
        if(v.empty()) return a;
        int left = fp(v, k);
        if(left == -1) return a;
        int right = lp(v, k);
        a[0] = left; a[1] = right;
        return a;
    }
};