class Solution {
public:
    int findLengthOfLCIS(vector<int>&v) {
        int n = v.size();
        int l=0, r=1; int a=1, c=1;
        while(r<n){
            if(v[r-1]<v[r]){
                c++; r++;
            }else{
                a = max(a,c);
                c=1; l=r; r++;
            }
        }
        a= max(a,c);
        return a;
    }
};