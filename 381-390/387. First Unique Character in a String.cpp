class Solution {
public:
    int firstUniqChar(string s){
        int n=s.size();
        // ff = index :: ss = frequency
        vector<pair<int,int>> v(26);
        for(int i=0; i<26; i++){
            v[i] = {n,0};
        }
        for(int i=0; i<n; i++){
            v[s[i]-'a'].first = min(v[s[i]-'a'].first, i);
            v[s[i]-'a'].second++;
        }
        int minidx=INT_MAX;
        for(int i=0; i<26; i++){
            if(v[i].second==1) minidx=min(minidx,v[i].first);
        }
        return minidx!=INT_MAX ? minidx : -1;
    }
};