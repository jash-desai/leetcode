class Solution {
public:
    // int rec(int n, int k){
    //     if(n==0) return 1;
    //     return ((rec(n-1,k)+k)%n);
    // }
    int rec(int n, int k, vector<int> &v, int idx){
        if(n==1) return v[0];
        idx = (idx+k)%n;
        v.erase(v.begin() + idx);
        return rec(n-1,k,v,idx);
    }
    int findTheWinner(int n, int k) {
        // return rec(n,k)+1;
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i]=i+1;
        return rec(n,--k,v,0);
    }
};