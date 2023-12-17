class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        string c = t.substr(1, t.size()-2);
        return (c.find(s)!=-1);
    }
};