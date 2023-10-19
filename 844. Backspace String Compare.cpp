class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss, tt;
        for(char &c : s){
            if(c=='#'){
                if(ss.size()) ss.pop_back();
                else continue;
            } 
            else ss += c;
        }
        for(char &c : t){
            if(c=='#'){
                if(tt.size()) tt.pop_back();
                else continue;
            } 
            else tt += c;
        }
        cout << ss << ' ' << tt;
        return (ss==tt);
    }
};