// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long i=1, j=n, k=-1, a=-1;
        while(i<=j){
            k=(i+j)/2;
            if(isBadVersion(k)){
                a=k;
                j=k-1;
            }else{
                i=k+1;
            }
        }
        return a;
    }
};