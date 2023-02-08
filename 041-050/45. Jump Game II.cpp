class Solution {
public:
    int jump(vector<int> &v) {
        int n=v.size();
        if(n<2) return 0;
        int cur_end = 0, cur_farthest = 0, jumps = 0;
        for (int i=0; i<n-1; i++) {
            cur_farthest = max(cur_farthest, i + v[i]);
            if (i == cur_end) {
              jumps++;
              cur_end = cur_farthest;
            }
        }
        return jumps;
    }
};