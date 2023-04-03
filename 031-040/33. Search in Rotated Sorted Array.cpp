class Solution {
public:
    int search(vector<int>& v, int k) {
        int n=v.size();
        int i=0, j=n-1;
        while(i<=j){
            int m=(i+j) >> 1;
            if(v[m]==k) return m;
            if(v[i]<=v[m]){
                if(v[i]<=k and k<=v[m]) j=m-1;
                else i = m+1;
            }else{
                if(k>=v[m] and k<=v[j]){
                    i = m+1;
                }else{
                    j = m-1;
                }
            }
        }
        return -1;
    }
};