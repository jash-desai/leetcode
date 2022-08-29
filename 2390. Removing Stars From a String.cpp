class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        int i=0, j=0;
        while(i<n){
            if(s[i] != '*' and i==j){
                i++, j++;
            }else if(i!=j and s[i] != '*'){
                s[j++] = s[i++];
            }else if(s[i]=='*'){
                i++, j--;
            }
        }
        return s.substr(0,j);
    }
};