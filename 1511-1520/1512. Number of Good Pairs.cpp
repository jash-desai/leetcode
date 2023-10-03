class Solution {
public:
    int numIdenticalPairs(vector<int>&v) {
        unordered_map<int,int>mp; int a = 0;
        for(int &x : v) mp[x]++;
        for(auto &[i, x]:mp) if(x>1) a += (x*(x-1))/2;
        return a;   
    }
};