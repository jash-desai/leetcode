class Solution {
public:
    double findMedianSortedArrays(vector<int>&a, vector<int>&b) {
        if(a.empty()){
            int idx = size(b)/2;
            if(size(b)%2) return (double)b[idx];
            return (b[idx] + b[idx - 1]) / 2.0;
        }else if(b.empty()){
            int idx = size(a)/2;
            if(size(a)%2) return (double)a[idx];
            return (a[idx] + a[idx - 1]) / 2.0;
        }
        if(size(a)>size(b)) return findMedianSortedArrays(b,a);
        int na = size(a), nb = size(b), n = na+nb;
        int l = 0, r = na;
        while(l<=r){
            int i = l + ((r-l) >> 1);
            int j = ((n+1) >> 1) - i;
            int l1 = (i==0) ? INT_MIN : a[i-1];
            int l2 = (j==0) ? INT_MIN : b[j-1];
            int r1 = (i==na) ? INT_MAX : a[i];
            int r2 = (j==nb) ? INT_MAX : b[j];
            if(l1<=r2 and l2<=r1){
                if(n%2) return (double)max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            if(l1 > r2) r = i-1;
            else l = i+1;
        }
        return 0.0;
    }
};