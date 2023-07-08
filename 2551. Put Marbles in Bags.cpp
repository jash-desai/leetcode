class Solution {
public:
    long long putMarbles(vector<int>&v, int k) {
        if(k==1 or k==size(v)) return 0;
        vector<int> c; int n = size(v);
        for(int i=0; i<n-1; i++) c.push_back(v[i] + v[i+1]);
        sort(begin(c),end(c)); long long int mn = 0,mx = 0;
        for(int i=0; i<(k-1); i++){ mn += c[i]; mx += c[n-2-i]; }
        return mx-mn;
    }
};