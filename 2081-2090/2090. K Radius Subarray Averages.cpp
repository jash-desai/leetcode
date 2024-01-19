class Solution {
public:
    vector<int> getAverages(vector<int>&v, int k) {
        long long int n=v.size(), sum = 0;
        vector<int> ans(n, -1);
        if(n<=(2*k)) return ans;
        for(int i=0; i<=(2*k); i++) sum += v[i];
        int i=0, j=(2*k);
        while(j<n){
            long long idx = i+k;
            ans[idx++] = (sum) / ((2*k)+1);
            sum -= v[i++];
            if(j!=n-1) sum += v[j+1];
            j++;
        }
        return ans;
    }
};