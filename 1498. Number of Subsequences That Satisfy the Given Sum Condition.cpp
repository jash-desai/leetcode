class Solution {
public:
    int numSubseq(vector<int>& v, int k) {
        int res = 0, mod = 1000000007, l = 0, r = v.size() - 1;
        vector<int> pre = {1};
        for(auto i = 1; i <= v.size(); ++i){
            pre.push_back((pre.back() << 1) % mod);   
        }
        sort(begin(v), end(v));
        while(l <= r){
            if (v[l] + v[r] > k) r--;
            else res = (res + pre[r - l++]) % mod;
        }
        return res;
    }
};