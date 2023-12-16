auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(256,0);
        for(char &x : s) v[x-'a']++;
        for(char &x : t) v[x-'a']--;
        for(int x : v){
            if(x != 0) return 0;
        }
        return 1;
    }
};