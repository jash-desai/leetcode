/*
class Solution {
public:
    long long minimumReplacement(vector<int>& v) {
        int n = v.size(); long long ans = 0, prev = v[n-1]; 
        for(auto i = n-2; i>=0; i--){
            long long cnt = (v[i] + prev - 1) / prev;
            ans += cnt - 1;
            prev = v[i] / cnt;
        } return ans;
    }
};
*/
class Solution {
public:
    long long minimumReplacement(vector<int>& v) {
        long long ans = 0; int n = v.size();
        for(int i = n-2; i >= 0; i--){
            if(v[i] <= v[i+1]) continue;
            long long cnt = ceil((v[i] + v[i+1] - 1LL) / (v[i+1]));
            ans += cnt - 1;
            v[i] = v[i] / cnt;
        } return ans;
    }
};