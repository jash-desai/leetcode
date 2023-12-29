class Solution {
public:
    int pivotIndex(vector<int>&v){
        int n=v.size();
        vector<int> ls(n); ls[0]=v[0];
        vector<int> rs(n); rs[n-1]=v[n-1];
        for(int i=1; i<n; i++){
            ls[i] = ls[i-1]+v[i];
            rs[n-i-1] = rs[n-i]+v[n-i-1];
        }
        for(int i=0; i<n; i++){
            if(ls[i]==rs[i]){
                return i;
            }
        }
        return -1;
    }
};