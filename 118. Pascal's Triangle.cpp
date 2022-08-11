// brute force approach
// #define pb push_back
// class Solution {
// public:
//     int ncr(int n, int r){
//         double res = 1;
//         for (int i = 1; i <= r; i++){
//             res = res * (n - r + i) / i;
//         }
//         return (int)res;
//     }
//     vector<int> temp(int n){
//         vector<int> t;
//         t.pb(1);
//         double res=1;
//         for(int i=1; i<=n; i++){
//             t.pb(ncr(n,i));
//         }
//         return t;
//     }
//     vector<vector<int>> generate(int n){
//         vector<vector<int>> a;
//         vector<int> t;
//         if(n==1){
//             t.pb(1);
//             a.pb(t);
//             return a;
//         }else if(n==2){
//            t.pb(1);  a.pb(t);
//            t.pb(1); a.pb(t);
//             return a;
//         }else{
//             t.pb(1);  a.pb(t);
//             t.pb(1); a.pb(t);
//             for(int i=2; i<n; i++){
//                 a.pb(temp(i));
//             }
//         }
//         return a;
//     }
// };


// approach 2
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> r(n);

        for(int i = 0; i < n; i++){
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++){
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }
        return r;
    }
};