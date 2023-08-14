class Solution {
public:
    int miceAndCheese(vector<int>&a, vector<int>&b, int k) {
        int n = a.size(), ans=0;
        vector<int> diff(n);
        for(int i=0; i<n; i++){
            diff[i] = (a[i]-b[i]);
            ans += b[i];
        }
        sort(diff.begin(), diff.end());
        for(int i = n-1; i > n-1-k; i--){
            ans += diff[i];
        }
        return ans;
    }
};