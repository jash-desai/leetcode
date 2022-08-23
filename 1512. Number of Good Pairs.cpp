class Solution {
public:
    int numIdenticalPairs(vector<int>&v) {
        int n=v.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }  
        int a =0;
        for(auto x:mp){
            if(x.second>=2){
              a+=x.second*(x.second-1)/2;
            }
        }
        return a;   
    }
};