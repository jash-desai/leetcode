class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        int a=0;
        for(char c:s){
            m[c]++;
            if(m[c]%2==0){
                a += m[c];
                m[c]=0;
            }
        }
        for(auto x: m) {
            if(x.second==1) {
              a++;
              break;
            }  
        }
        return a;
    }
};