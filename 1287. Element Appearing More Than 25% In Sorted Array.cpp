class Solution {
public:
    int findSpecialInteger(vector<int>&v) {
        int n = v.size();
        int f = n/4;
        unordered_map<int, int> mp;
        for(int &x : v){
            mp[x]++;
            if(mp[x] > f) return x;
        }
        return -1;
    }
};