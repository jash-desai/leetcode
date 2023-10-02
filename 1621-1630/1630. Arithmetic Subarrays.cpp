class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>&v, vector<int> &l, vector<int> &r) {
        int n=v.size();
        int m=l.size();
        assert(m==r.size());
        vector<bool> res;
        for(auto i=0, j=0; i<m; i++) {
            vector<int> t(begin(v) + l[i], begin(v) + r[i] + 1);
            sort(begin(t), end(t));
            for (j=2; j<t.size(); j++){
                if (t[j] - t[j - 1] != t[1] - t[0]) break;
            }
            res.push_back(j == t.size());
        }
        return res;
    }
};