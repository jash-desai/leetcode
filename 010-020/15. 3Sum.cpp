class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> a;
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            int k = -v[i];
            int l=i+1; int r=n-1;
            while(l<r){
                int s = v[l] + v[r];
                if(s==k){
                    vector<int> t = {v[i],v[l],v[r]};
                    a.push_back(t);
                    while (l < r && v[l] == t[1]) l++;
                    while (l < r && v[r] == t[2]) r--;
                }else if(s<k){
                    l++;
                }else{
                    r--;
                }
            }
            while(i+1<n && v[i+1] == v[i]) i++;
        }
        return a;
    }
};