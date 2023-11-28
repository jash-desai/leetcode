class Solution {
public:
    vector<int> findOriginalArray(vector<int>& A) {
        if (A.size() % 2) return {};
        int N=A.size();
        multiset<int> s(begin(A), end(A));
        vector<int> ans;
        for (int i = 0; i < N; i += 2) {
            int n = *s.begin();
            ans.push_back(n);
            s.erase(s.begin());
            if (s.find(2 * n) == s.end()) return {};
            s.erase(s.find(2 * n));
        }
        return ans;
    }
};