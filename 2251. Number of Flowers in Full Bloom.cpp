class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& v, vector<int>& p) {
        /*
        // brute force : 
        int n = p.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int k = p[i];
            int count = 0;
            for(auto x : v){
                int s = x[0], e = x[1];
                if(s<=k and k<=e) count++;
            }
            ans[i] = count;
        }
        return ans;
    */

    // optimized (?) : 
        vector<int> starts;
        vector<int> ends;
        
        for (vector<int>& flower : v) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1] + 1);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> ans;
        
        for (int person : p) {
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin();
            ans.push_back(i - j);
        }
        
        return ans;
        
    }
};