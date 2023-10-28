class Solution {
private:
    int solve(vector<int> v, int k){
        int n = v.size(); int curr = 1e9;
        vector<int> left(k, 1e9), right;
        for(int i=k-1; i>=0; i--){
            curr = min(curr, v[i]);
            left[i] = min(left[i], curr);
        }
        curr = 1e9;
        for(int i=k; i<n; i++){
            curr = min(curr, v[i]);
            right.push_back(curr);
        }
        int ans = 0;
        for(int j{0}; j < right.size(); j++){
            curr = right[j];
            int i = lower_bound(left.begin(), left.end(), curr) - left.begin();
            int len = (k+j) - i + 1;
            ans = max(ans, len*curr);
        }
        return ans;
    }
public:
    int maximumScore(vector<int>&v, int k) {
        int n = v.size();
        return max(solve(v, k), solve(vector<int>(rbegin(v), rend(v)), n-k-1));
    }
};