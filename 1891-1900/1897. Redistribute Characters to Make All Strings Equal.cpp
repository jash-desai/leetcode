class Solution {
public:
    bool makeEqual(vector<string>& v) {
        map<char, int> mp;
        for(auto &s : v){
            for(char &c : s){
                mp[c]++;
            }
        }
        for(auto&[a, b] : mp){
            if(b%v.size()) return false;
        }
        return true;
    }
};