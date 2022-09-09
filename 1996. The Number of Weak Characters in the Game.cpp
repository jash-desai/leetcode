class Solution {
public:
     static bool comp(vector<int> &a, vector<int> &b){
          if (a[0]==b[0]) return a[1] > b[1];
          return a[0] < b[0];
     }
     int numberOfWeakCharacters(vector<vector<int>> &v){
          sort(v.begin(), v.end(), comp);
          int mtn = INT_MIN;
          int a = 0;

          for (int i = v.size()-1; i>=0; i--){
               if (v[i][1]<mtn) a++;
               mtn = max(mtn, v[i][1]);
          }
          return a;
     }
};