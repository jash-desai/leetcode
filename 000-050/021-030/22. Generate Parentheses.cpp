class Solution {
public:
    void rec(int n, vector<string>&a, string t, int op, int cl){
        if(t.size()==n*2){
            a.push_back(t);
            return;
        }
        if(op<n) rec(n,a,t+"(",op+1,cl);
        if(cl<op) rec(n,a,t+")",op,cl+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> a;
        string t;
        rec(n,a,t,0,0);
        return a;
    }
};