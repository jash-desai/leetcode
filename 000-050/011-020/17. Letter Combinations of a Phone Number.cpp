class Solution {
    vector<string> m = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void rec(string&s, vector<string>&ans, string temp, int idx){
        if(idx>=s.size()){ ans.push_back(temp); return; }
        int n = s[idx]-'0';
        for(char c : m[n]){
            temp.push_back(c);
            rec(s,ans,temp,idx+1);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string s) {
        if(!s.size()) return {};
        vector<string> ans; string temp;
        rec(s,ans,temp,0);
        return ans;
    }   
};