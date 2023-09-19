// class Solution {
// public:
//     int findDuplicate(vector<int>&v) {
//         int n = v.size(), l = 0, r = n-1, cnt;
//         while(l<=r){
//             int m = l + ((r-l) >> 1); cnt = 0;
//             for(int &x : v) if(x <= m) cnt++;
//             if(cnt<=m) l = m+1;
//             else r = m-1;
//         }
//         return l;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n = v.size();
        for(int i=0;i<n;i++){
            if(v[abs(v[i])-1]>0) v[abs(v[i])-1] = -v[abs(v[i])-1];
            else return abs(v[i]);
        }
        return 0;
    }
};