class Solution {
public:
    int numberOfBeams(vector<string> &v) {
        int ans = 0;
        int prevOnes = 0;
        for (string s : v) {
            int ones = count(begin(s), end(s), '1');
            if (ones > 0) {
                ans += prevOnes * ones;
                prevOnes = ones;
            }
        }
        return ans;
    }
};