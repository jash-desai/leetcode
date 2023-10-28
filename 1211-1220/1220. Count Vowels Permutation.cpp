// /*
class Solution{
    unordered_map<char, vector<char>> m;
    const int md = 1e9+7;
private:
    int rec(int n, int i, char prev, vector<vector<long long> > &dp){
        if(i > n) return 0;
        if(i==n){
            switch(prev){
                case 'a': return 1;
                case 'e': return 2;
                case 'i': return 4;
                case 'o': return 2;
                case 'u': return 1;
                default: return 5;
            }
        }
        int idx = prev - 'a';
        if(dp[i][idx] != -1) return dp[i][idx];
        long long ans = 0;
        for(auto next : m[prev]) ans += (rec(n, i+1, next, dp) % md);
        return dp[i][idx] = ans % md;
    }
public:    
    int countVowelPermutation(int n){
        m['c'] = {'a','e','i','o','u'};
        m['a'] = {'e'};
        m['e'] = {'a','i'};
        m['i'] = {'a','e','o','u'};
        m['o'] = {'i','u'};
        m['u'] = {'a'};
        vector<vector<long long> > dp(n+2, vector<long long>(27, -1));
        return rec(n,1,'c',dp);
    }
};
// */
/*
class Solution {
    int mod = 1e9 + 7;
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        long a1, e1, i1, o1, u1;
        for(int j=2; j<=n; j++){
            a1 = (e+i+u) % mod;
            e1 = (a+i) % mod; 
            i1  = (e+o) % mod;
            o1 = i % mod;
            u1 = (i+o) % mod;
            a = a1, e = e1, i=i1, o = o1, u = u1;       
        } return (a+e+i+o+u) % mod;
    }
};
*/