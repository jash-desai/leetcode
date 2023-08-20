class Solution {
    int ans = INT_MIN;
private:
    void rec(int i, int curr, vector<vector<int>>&v, vector<int>&cap){
    if(i==size(v)){
        for(int x : cap) if(x!=0) return;
        ans = max(ans, curr);
        return;
    }
    rec(i+1,curr,v,cap);
    cap[v[i][0]]--; cap[v[i][1]]++;
    rec(i+1,curr+1,v,cap);
    cap[v[i][0]]++; cap[v[i][1]]--;
}
public:
    int maximumRequests(int n, vector<vector<int>>&v) {
        vector<int> cap(n, 0);
        rec(0,0,v,cap);
        return ans;
    }
};