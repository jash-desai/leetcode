class Solution {
public:
    int jump(vector<int>&v) {
        if(size(v) < 2) return 0;
        int n = size(v), ans=0, curr=0, maxCurr=0;
        for(int i=0; i<n-1; i++){
            curr = max(curr, v[i]+i);
            if(i==maxCurr){
                ans++;
                maxCurr = curr;
                if(maxCurr == n-1) return ans;
            }
        }
        return ans;
    }
};