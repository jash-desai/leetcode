class Solution {
public:
    int minPairSum(vector<int>& v) {
        sort(begin(v), end(v));
        int ans=-1e9; int i=0, j=v.size()-1;
        while(i<j){
            ans = max(ans, v[i]+v[j]);
            i++, j--;
        }
        return ans;
    }
};