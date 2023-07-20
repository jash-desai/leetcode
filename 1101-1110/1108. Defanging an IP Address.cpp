class Solution {
public:
    string defangIPaddr(string s) {
        string a;
        int n=s.size();
        // method 1
        for(int i=0; i<n; i++){
            if(i<n-1 and s[i+1]=='.'){
                a += s[i];
                a += '[';
            }else if(s[i]=='.'){
                a += '.';
                a += ']';
            }else{
                a += s[i];
            }
        }
        // method 2
        // for(int i=0; i<n; i++){
        //     if(s[i]=='.'){
        //         a += "[.]";
        //     }else{
        //         a += s[i];
        //     }
        // }
        return a;
    }
};