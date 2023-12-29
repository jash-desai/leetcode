class Solution {
public:
    int mirrorReflection(int p, int q) {
        int com = gcd(p, q);
        int x = (p/com)%2, y = (q/com)%2;
        return y? 2-x:-1+x;
    }
};