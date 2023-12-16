class Solution {
public:
    string destCity(vector<vector<string>>&mat) {
        map<string, int> mp;
        for(auto&m : mat){
            string a = m[0], b = m[1];
            mp[a]++;
            if(!mp.count(b)) mp[b] = 0;
        }
        for(auto&[u, in] : mp ){
            if(in==0) return u;
        }
        return "-1";
    }
};