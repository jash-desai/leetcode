class Solution {
public:
    vector<int> runningSum(vector<int>&v){
        int n=v.size();
        vector<int> a(n);
        a[0]=v[0];
        for(int i=1; i<n; i++){
            a[i] = a[i-1]+v[i];
        }
        return a;
    }
};