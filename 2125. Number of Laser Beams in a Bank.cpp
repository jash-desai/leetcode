class Solution {
public:
    int numberOfBeams(vector<string> &v) {
        int ans = 0;
        int prevOnes = 0;
        for (const string &row : v) {
            const int ones = count(begin(row), end(row), '1');
            if (ones > 0) {
                ans += prevOnes * ones;
                prevOnes = ones;
            }
        }
        return ans;
    }
};