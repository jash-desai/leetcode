class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        int n=s.size(); int m=p.size();
        if(n<m) return v;
        vector<int> fp(26,0);
        vector<int> ws(26,0);
        for(int i=0; i<m; i++){
            fp[p[i]-'a']++;
            ws[s[i]-'a']++;
        }
        if(fp == ws){
            v.push_back(0);
        }
        for(int i=m; i<n; i++){
            ws[s[i-m] - 'a']--;
            ws[s[i]-'a']++;
            if(fp==ws) v.push_back(i-m+1);
        }
        return v;
    }
};