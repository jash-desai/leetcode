class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return 0;
        int t=n;
        int count=0;
        while(t>1){
            t >>= 1;
            count++;
        }
        return (t<<count)==n ? 1 : 0;
    }
};