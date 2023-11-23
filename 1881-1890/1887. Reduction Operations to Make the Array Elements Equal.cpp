class Solution {
public:
    int reductionOperations(vector<int>& v) {
        int n = v.size();
        map<int, int> mp;
        sort(begin(v), end(v), greater<int>());
        int ans = 0, cnt = 1;
        for(int i=1; i<n; i++){
            if(v[i]!=v[i-1]){
                ans += cnt;
                cnt++;
            }else{
                cnt++;
            }
        }
        return ans;
    }
};