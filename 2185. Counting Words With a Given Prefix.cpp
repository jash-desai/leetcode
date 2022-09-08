class Solution {
public:
    int prefixCount(vector<string>& v, string s) {
        int c=0;
        for(string x:v){
            int i=0, j=0;
            while(j<s.size() and i<x.size()){
                if(x[i]==s[j]){
                    i++, j++;
                }else{
                    break;
                }
            }
            if(j==s.size()) c++;
        }
        return c;
    }
};