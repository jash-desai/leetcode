class Solution {
public:
    void rec(string s, vector<string>&ans, string temp, string m[], int idx){
        if(idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        int n=s[idx]-'0';
        string val=m[n];
        for(int i=0; i<val.size(); i++){
            temp.push_back(val[i]);
            rec(s,ans,temp,m,idx+1);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string s) {
        vector<string> ans;
        if(!s.size()) return ans;
        string temp;
        string m[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        rec(s,ans,temp,m,0);
        return ans;
    }   
};