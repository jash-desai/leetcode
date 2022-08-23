class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>&v, int k) {
        int n=v.size();
        vector<bool> a(n);
        int m = *max_element(v.begin(), v.end());
        for(int i=0; i<n; i++){
            if(v[i]+k >= m){
                a[i]=1;
            }
        }
        return a;
    }
};