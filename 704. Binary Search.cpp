class Solution {
public:
    int search(vector<int>&v, int k) {
        int n=v.size();
        int i=0, j=n-1, p=0;
        while(i<n and j>-1 and i<=j){
            p=(i+j)/2;
            if(v[p]==k){
                return p;
            }else if(v[p]<k){
                i=p+1;
            }else if(v[p]>k){
                j=p-1;
            }
        }
        return -1;
    }
};