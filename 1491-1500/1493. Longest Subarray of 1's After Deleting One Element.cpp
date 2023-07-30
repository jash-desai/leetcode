class Solution {
public:
    int longestSubarray(vector<int>&v) {
        int n = size(v), i = 0, j = 0, cnt = 0, ans = 0;
        for(j=0; j<n; j++){
            if(v[j]==0) cnt++;
            if(cnt>1 and v[i++]==0) cnt--;
            ans = max(ans, j-i);
        }
        return ans;
    }
};