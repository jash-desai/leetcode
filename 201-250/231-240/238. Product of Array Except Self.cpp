class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n=v.size(); vector<int> a(n,1), b(n,1); a[0]=v[0];
        for(int i=1; i<n; i++) a[i] = a[i-1]*v[i];
        b[n-1]=v[n-1]; vector<int> ans(n,0);
        for(int i=n-2; i>=0; i--) b[i] = b[i+1]*v[i];
        for(int i=0; i<n; i++){
            if(i!=0 and i!=n-1) ans[i] = a[i-1]*b[i+1];
            else if(i==0) ans[i]=b[i+1];
            else if(i==n-1) ans[i]=a[i-1];
        }
        return ans;
    }
};