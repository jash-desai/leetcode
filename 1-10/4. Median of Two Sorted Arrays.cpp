class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int na=a.size();    int nb=b.size();
        int n=na+nb;
        vector<int> v(n);
        int i=0, j=0;
        int k=0;
        while(i<na and j<nb){
            if(a[i]<b[j]){
                v[k++] = a[i++];
            }else{
                v[k++] = b[j++];
            }
        }
        while(i<na){
            v[k++] = a[i++];
        }
        while(j<nb){
            v[k++] = b[j++];
        }
        
        if(n%2==1){
            return (double)v[(n)/2];
        }else{
            double x = v[n/2 - 1] + v[n/2];
            return (double)x/2;
        }
    }
};