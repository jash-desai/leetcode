class Solution {
public:
    string mergeAlternately(string a, string b) {
        string ans = ""; int i=0, j=0;
        while(i<a.length() or j<b.length()){
            if(i<a.length()) ans += a[i];
            if(j<b.length()) ans+=b[j];
            i++; j++;
        }
        return ans;
    }
};