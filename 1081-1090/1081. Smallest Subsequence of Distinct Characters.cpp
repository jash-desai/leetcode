class Solution {
public:
    string smallestSubsequence(string s) {
        string ans; vector<int> vis(26, 0), freq(26, 0);
        for(char c : s) freq[c-'a']++;
        for(char c : s){
            freq[c-'a']--;
            if(vis[c-'a']) continue;
            while(ans.size() and ans.back()>c and freq[ans.back()-'a']){
                vis[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            vis[c-'a'] = 1;
            ans.push_back(c);
        }
        return ans;
    }
};