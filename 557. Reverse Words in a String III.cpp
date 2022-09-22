class Solution {
public:
    string reverseWords(string s) {
        vector<string> a; string t;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                a.push_back(t);
                t.clear();
            }else if(i==s.size()-1){
                t += s[i];
                a.push_back(t);
                t.clear();
            }else{
                t += s[i];
            }
        }
        for(int i=0; i<a.size(); i++){
            reverse(begin(a[i]), end(a[i]));
        }
        t.clear();
        for(int i=0; i<a.size(); i++){
            t += a[i];
            t += " ";
        }
        t.pop_back();
        return t;
    }
};