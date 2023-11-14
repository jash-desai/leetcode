class Solution {
public:
    int findPeakElement(vector<int> &v) {
        int n=v.size();
        int i=0, j=n-1;
        while(i<=j){
            int m = (i+j) >> 1;
            if((m==0 or v[m]>=v[m-1]) and (m==n-1 or v[m]>=v[m+1])) return m;
            if(m>0 and v[m-1]>=v[m]) j = m-1;
            else i=m+1;
        }
        return -1;
    }
};