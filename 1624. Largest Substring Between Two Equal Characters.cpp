class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int ans = -1;
        for(auto &[c, v] : mp){
            if(v.size()<2) continue;
            int n = v.size();
            int curr = v[n-1] - v[0] - 1;
            ans = max(ans, curr);
        }
        return ans;
    }
};