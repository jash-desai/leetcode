class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        if(s2.size()<s1.size()) return 0;
        for(int i=0; i<=s2.size()-s1.size(); i++){
            string s = s2.substr(i, s1.size());
            sort(s.begin(), s.end());
            if(s1 == s) return 1;
        }
        return 0;
    }
};