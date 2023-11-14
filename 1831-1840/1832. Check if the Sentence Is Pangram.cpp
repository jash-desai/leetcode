class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool> v(26,0);
        for(auto c:s){
            v[c-'a'] = 1;
        }
        for(auto x:v){
            if(!x) return 0;
        }
        return 1;
    }
};