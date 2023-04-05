class Solution {
public:
    int minimizeArrayValue(vector<int>& v) {
        long long sum = 0, res = 0;
        for (int i = 0; i < v.size(); ++i) {
            sum += v[i];
            // res = max(res, (sum + i) / (i + 1));
            res = max(res, ((long long)ceil(double(sum)/(i+1))));
        }
        return res;
    }
};