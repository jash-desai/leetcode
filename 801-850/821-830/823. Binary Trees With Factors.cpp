class Solution {
    const int mod = 1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& v) {
        int n=v.size();
        sort(v.begin(), v.end());
        map<int,long long int> m;
        for(int i=0; i<n; i++){
            m.insert({v[i],1});
        }
        for(int i=1; i<n; i++){
            auto it0 = m.find(v[i]);
            long long int count=0;
            for(int j=0; j<i; j++){
                if(v[i]%v[j]==0){
                    auto it = m.find(v[i]/v[j]);
                    auto it2 = m.find(v[j]);
                    if(it!=m.end()){
                        count += (it->second) * (it2->second);
                    }
                }
            }
            it0->second += count;   
        }
        long long int ans=0;
        for(auto &[a, b] : m) ans = (ans+b)%mod;
        return ans%mod;
    }
};