class Solution {
private:
    long long calculate(vector<int>&a, vector<int>&b, long long median){
        long long ans=0;
        for(int i=0; i<a.size(); i++) ans += abs((a[i]-median)*b[i]);
        return ans;
    }
public:
    long long minCost(vector<int>&a, vector<int>&b){
        int n = a.size(); long long total=0, sum=0, median;
        vector<pair<int,int>> vp;
        for(int i=0; i<n; i++) vp.push_back({a[i], b[i]});
        sort(vp.begin(),vp.end());
        for(int i=0; i<n; i++) sum += vp[i].second;
        int i=0;
        while(total < (sum+1)>>1 and i<n){
            total += vp[i].second;
            median = vp[i++].first;
        }
        return calculate(a,b,median);
    }
};