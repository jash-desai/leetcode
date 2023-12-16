class Solution {
private:
    bool fx(vector<int>&v, int &k, int&m){
        int curr = 0; for(int i=0; i<m; i++) curr += v[i];
        if(curr>=k) return 1;
        for(int i=m; i<size(v); i++){
            curr -= v[i-m]; curr += v[i];
            if(curr>=k) return 1;
        }
        return 0;
    }
public:
    int minSubArrayLen(int k, vector<int>&v){
        int curr = 0; for(int x:v) curr += x;
        if(curr<k) return 0;
        /*
        int l = 1, r = size(v), m, ans;
        while(l<=r){
            m = (l + ((r-l) >> 1));
            if(fx(v,k,m)){
                ans = m;
                r = m-1;
            }else l = m+1;
        }
        return ans;
        */
        curr = 0; int ans = INT_MAX, i = 0, j = 0;
        while(j<size(v)){
            curr += v[j];
            while(curr >= k){
                ans = min(ans, j-i+1);
                curr -= v[i++];
            }
            j++;
        }
        return ans;
    }
};