#define ff first
#define ss second
class Solution {
public:
    int eliminateMaximum(vector<int>& a, vector<int>& b) {
        vector<pair<int,int>> v; int n = a.size();
        for(int i=0; i<n; i++){
            v.push_back({a[i], b[i]});
        }
        sort(begin(v), end(v), [](const auto&a, const auto&b){
            // return (a.ff == b.ff) ? a.ss>b.ss : a.ff<b.ff;
            return ((double)a.ff/(double)a.ss)<((double)b.ff/(double)b.ss);
        });
        int ans = 0;
        for(int i=0; i<n; i++){
            float time = ((float)v[i].ff / v[i].ss);
            if(time <= i) break;
            ans++;
        }
        return ans;
    }
};