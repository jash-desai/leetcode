class Solution {
public:
    bool winnerOfGame(string s) {
        int a = 0, b = 0;
        for(int i=1; i<s.size()-1; i++){
            if(s[i-1]=='A' and s[i]=='A' and s[i+1]=='A') a++;
            if(s[i-1]=='B' and s[i]=='B' and s[i+1]=='B') b++;
        }
        return (a>b);
    }
};