class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int c=0; int i=n-1;
        while(s[i]==' '){
            s.pop_back();
            i--;
        }
        i=s.size()-1;
        while(i>=0){
            if( (s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') ){
                c++;
                i--;
            }else{
                break;
            }
        }
        return c;
    }
};