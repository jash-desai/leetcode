class Solution {
public:
    bool isIsomorphic(string s, string t){
        unordered_map<char, char> m;
        unordered_set<char> mapped;
        for(int i=0; i<s.size(); i++){
            if(m.count(s[i])){
                s[i] = m[s[i]];
                if(s[i] != t[i]) return false;
            }else{
                if(mapped.count(t[i])) return false;
                m[s[i]] = t[i];
                mapped.insert(t[i]);
            }
        }
        return true;
    }
};