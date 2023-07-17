class Solution {
private:
    int rec(int n, int curr, int copy){
        if(curr > n or copy > n) return INT_MAX;
        if(curr == n) return 0;
        if(copy==0) return 1 + rec(n, curr, curr);
        int ans1 = INT_MAX, ans2 = INT_MAX;
        if(curr != copy){
            ans1 = rec(n, curr, curr); // copy
            ans2 = rec(n, curr+copy, copy); // paste
        }else{
            ans2 = rec(n, curr+copy, copy); // paste
        }
        if(ans1==INT_MAX and ans2==INT_MAX) return INT_MAX;
        return 1 + min(ans1,ans2);
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        return rec(n,1,0);
    }
};