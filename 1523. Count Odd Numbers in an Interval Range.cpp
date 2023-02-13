class Solution {
public:
    int countOdds(int a, int b) {
        if(b-a==1) return 1;
        if(a%2==1 and b%2==1) return ((b-a+1)/2 + 1);
        else return ((b-a+1)/2);
    }
};