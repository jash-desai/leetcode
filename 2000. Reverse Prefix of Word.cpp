class Solution {
public:
    string reversePrefix(string s, char c) {
        if(s.find(c)==string::npos) return s;
        int i=0;
        while(s[i]!=c){
            i++;
        }
        string t = s.substr(0,i+1);
        reverse(t.begin(), t.end());
        t += s.substr(i+1, s.size()-i-1);
        return t;
    }
};