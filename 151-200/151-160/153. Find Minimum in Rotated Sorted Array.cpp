class Solution {
public:
    int findMin(vector<int>&v){
        int l = 0, r = size(v)-1, m, ans = INT_MAX;
        while(l<=r){
            m = (l + ((r-l) >> 1));
            if(v[l] < v[r]){
                ans = min(ans, v[l]); break;
            }
            if(v[l] <= v[m]){
                ans = min(ans, v[l]);
                l = m+1;
            }else{
                ans = min(ans, v[m]);
                r = m-1;
            }
        }
        return ans;
    }
};