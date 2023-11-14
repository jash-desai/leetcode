class Solution {
public:
    int candy(vector<int>&v) {
        if(v.size()==1) return 1;
        int n = v.size(); vector<int> cnt(n, 1);
        if(v[0] > v[1]) cnt[0]++;
        for(int i=1; i<=n-1; i++){
            if(v[i]>v[i-1]) cnt[i]=cnt[i-1]+1;
        }
        for(int i=n-2; i>=0; i--){
            if(v[i]>v[i+1]){
                cnt[i] = max(cnt[i], cnt[i+1]+1);
            }
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};