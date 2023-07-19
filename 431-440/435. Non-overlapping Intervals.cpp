// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>&v) {
//         sort(begin(v), end(v));
//         vector<int> prev = v[0]; int ans = -1;
//         for(auto &curr : v){
//             if(curr[0]<prev[1] and curr[1]<=prev[1]){
//                 ans++; prev = curr;
//             }else if(curr[0]<prev[1] and curr[1]>prev[1]){
//                 ans++;
//             }else prev = curr;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(begin(v),end(v), [](auto&a, auto&b){
            return a[1]<b[1];
        });
        int ans {0}, n = size(v);
        int end = v[0][1];
        for(int i=1; i<n; i++){
            if(v[i][0] < end) ans++;
            else end = v[i][1];
        }
        return ans;
    }
};