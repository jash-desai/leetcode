class Solution {
public:
    bool isp(string s){
        string t=s;
        reverse(t.begin(), t.end());
        return (s==t);
    }
    void rec(string s, vector<vector<string>>&a, vector<string>&t){
        if(!s.size()){
            a.push_back(t);
            return;
        }
        for(int i=1; i<=s.size(); i++){
            string x = s.substr(0,i);
            if(isp(x)){
                t.push_back(x);
                string y = s.substr(i,s.size()-i);
                rec(y,a,t);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> a;
        vector<string> t;
        rec(s,a,t);
        return a;
    }
};