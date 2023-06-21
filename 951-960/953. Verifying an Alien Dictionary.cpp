class Solution {
public:
    bool isAlienSorted(vector<string>&v, string s) {
        unordered_map<char,char> map;
        for(int i=0; i<26; i++){
            map[s[i]]= ('a'+i);
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                v[i][j]= map[v[i][j]];
            }
        }
        return is_sorted(v.begin(),v.end());
    }
};