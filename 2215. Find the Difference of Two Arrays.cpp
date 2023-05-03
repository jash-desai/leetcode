class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {
		vector<vector<int>> ans(2);
        unordered_set<int> s1(a.begin(),a.end());
        unordered_set<int> s2(b.begin(),b.end());
        for(int x : s1) if(!s2.count(x)) ans[0].push_back(x);
        for(int x : s2) if(!s1.count(x)) ans[1].push_back(x);
        return ans;
    }
};