class MaxBIT {
    vector<int> bit;
public:
    MaxBIT(int size) {
        bit.resize(size + 1);
    }
    int get(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx)
            ans = max(ans, bit[idx]);
        return ans;
    }
    void update(int idx, int val) {
        for (; idx < bit.size(); idx += idx & -idx){
            bit[idx] = max(bit[idx], val);
        }
    }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v) {
        int nUnique = compress(v);
        MaxBIT bit(nUnique);
        for(int i = 0; i < v.size(); ++i) {
            int subLongest = bit.get(v[i]) + 1;
            bit.update(v[i], subLongest);
            v[i] = subLongest;
        }
        return v;
    }
    int compress(vector<int>& arr){
        vector<int> ans(arr);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for(int& x : arr){
            x = lower_bound(ans.begin(), ans.end(), x) - ans.begin() + 1;
        }
        return ans.size();
    }
};