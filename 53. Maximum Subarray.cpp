class Solution {
public:
    int maxSubArray(vector<int> &v) {
        int max_sum = v[0];
        int cur_sum = v[0];
        for (int i = 1; i < v.size(); i++) {
            cur_sum = max(v[i], cur_sum + v[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }

};