class Solution {
public:
    int minOperations(vector<int>&v, int x) {
        int n=v.size(), ans=0, s=0, e=0;
        int ts=accumulate(v.begin(), v.end(),0);
        if(ts==x) return n;
        int sum=ts-x, cs=0;
        while(e<n){
            cs+=v[e];
            while(s<e && cs>sum){
                cs-=v[s++];
            }
            if(cs==sum){
                ans=max(ans, e-s+1);
            }
            e++;
        }
        return ans==0 ? -1 : n-ans;
    }
};