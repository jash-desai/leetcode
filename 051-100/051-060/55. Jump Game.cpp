class Solution {
public:
    bool canJump(vector<int>&v) {
        int a = v[0], n=v.size();
        if(a>=n-1) return 1;
        if(a==0) return 0;
        for(int i=1; i<n; i++){
            if(v[i]==0 and i!=n-1 and a<=i) return 0;
            a = max(a,i+v[i]);
            if(a>=n-1) return 1;
        }
        return 0;
    }
};