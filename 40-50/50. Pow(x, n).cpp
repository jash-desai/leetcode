class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        // using logarithms
        return (x<0) ? (n%2==0 ? (exp(n*log(-x))) : -exp(n*log(-x))) : exp(n*log(x));
        // using in-built pow fxn
        return pow(x,n);

    }
};