class Solution {
public:
    long zeroFilledSubarray(vector<int>& v) {
        long cnt = 0, curr = 0;
        for (int n : v) {
            if (n == 0) {
                cnt += ++curr;
            }else{
                curr = 0;
            }
        }
        return cnt;
    }
};