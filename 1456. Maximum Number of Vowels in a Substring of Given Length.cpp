class Solution {
public:
    bool iv(char &c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int i=0, j=0;
        int a=0, c=0;
        for(j=i; j<k; j++){
            if(iv(s[j])) c++;
            a = max(a,c);
        }
        while(j<s.size()){
            if(iv(s[i])) c--;
            if(iv(s[j])) c++;
            i++, j++;
            a = max(a,c);
        }
        c=0;
        while(i<j){
            if(iv(s[i++])) c++;
        }
        a = max(a,c);
        return a;
    }
};