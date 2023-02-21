class Solution {
public:
    int missingNumber(vector<int>&v) {
        sort(v.begin(), v.end());
        int n=v.size();
        for(int i=0; i<n; i++){
            if(v[i]!=i) return i;
        }
        return n;
    }
};