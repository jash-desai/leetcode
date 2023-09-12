class Solution {
public:
    int minDeletions(string s) {
        int n = s.size(); vector<int> freq(26, 0); int mx = 0;
        for(char c : s) freq[c-'a']++, mx = max(mx, freq[c-'a']);
        vector<int> mp(mx+1, 0); int ans = 0;
        for(int i=0; i<26; i++) if(freq[i]) mp[freq[i]]++;
        for(int i=mx; i>0; i--){
            if(mp[i]==0 or mp[i]==1) continue;
            else{
                ans += mp[i]-1;
                mp[i-1] += mp[i]-1; mp[i]=1; 
            }
        }
        return ans;
    }
};