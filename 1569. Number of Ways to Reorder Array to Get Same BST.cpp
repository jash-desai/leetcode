class Solution {
private:
    vector<vector<long long>> table;
    long long mod;
    long long dfs(vector<int> &v){
        int n=v.size();
        if(n <= 2) return 1;      

        vector<int> left, right;
        for(int i=1; i<n; i++){
            if(v[i] < v[0]) left.push_back(v[i]);
            else right.push_back(v[i]);
        }

        long long leftRes = dfs(left) % mod;
        long long rightRes = dfs(right) % mod;

		int leftSz = left.size();
        return ((((table[n-1][leftSz] * leftRes) % mod) * rightRes) % mod);
    }

public:
    int numOfWays(vector<int>& v) {
        int n = v.size(); mod = 1e9+7;
        table.resize(n+1);
        for(int i=0; i<(n+1); i++){
            table[i] = vector<long long>(i+1, 1);
            for(int j=1; j<i; j++){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
        return (dfs(v) % mod) - 1;
    }
};