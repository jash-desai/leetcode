class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(!n) return 0;
        int ml=INT_MIN;
        int cl=0;
        vector<int> v(256,-1);
        int l=0, r=0;
        while(r<n){
            if(v[s[r]]!=-1) l = max(v[s[r]]+1, l);
            v[s[r]]=r;
            ml=max(ml, r-l+1);
            r++;
        }
        return ml;
    }
};