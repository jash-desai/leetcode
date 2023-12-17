class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return 0;
        // int t=n;
        // int count=0;
        // while(t>1){
        //     t >>= 2;
        //     count+=2;
        // }
        // return (t<<count)==n ? 1 : 0;
        if (n > 0 && (n & (n - 1)) == 0) {
            int zero_count = 0;
            while (n > 1) {
                zero_count++;
                n >>= 1;
            }
            return zero_count % 2 == 0;
        }
        return false;
    }
};