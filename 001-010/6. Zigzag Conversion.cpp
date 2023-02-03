class Solution {
public:
    string convert(string s, int k) {
        if(k <= 1) return s;
        vector<string> v(k,""); 
        int j = 0; bool f = 0;
        for(int i=0; i<s.length(); i++){
            if(j == k-1 or j==0) f=!f; 
            v[j] += s[i];
            if(f) j++;
            else j--;
        }
        string res;
        for(auto &it : v) res += it; 
        return res;
    }
};