class Solution {
public:
    int findMin(vector<int>& v){
        int n=v.size();
        int a=INT_MAX;
        int i=0, j=n-1;
        while(i<=j){
            int m=(i+j) >> 1;
            if (v[i]<v[j]) {
                a = min(a, v[i]);
                break;
            }
            if(v[i]<=v[m]){
                a = min(a,v[i]);
                i=m+1;
            }else{
                a = min(a,v[m]);
                j=m-1;
            }
        }
        return a;
    }
};