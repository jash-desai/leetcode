class Solution {
public:
    string removeStars(string s) {
        int i=0, j=0;
        while(i<s.size()){
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