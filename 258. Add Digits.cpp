class Solution {
public:
    int addDigits(int n) {
        // naive approach -
        // int sum = 0;
        // while (n > 0) {
        //     sum += n % 10;
        //     n = n / 10;
            
        //     if (n == 0 && sum > 9) {
        //         n = sum;
        //         sum = 0;  
        //     }
        // }
        // return sum; 

        // optimized math -
        if(n==0) return 0;
        return (n%9) ? (n%9) : 9;
    }
};