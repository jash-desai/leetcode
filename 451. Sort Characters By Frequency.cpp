class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(char c : s) mp[c]++;
        vector<pair<char, int>> v;
        for(auto x : mp) v.push_back(x);
        sort(begin(v), end(v), [](auto &a, auto&b){
            return a.second > b.second;
        });
        string ans;
        for(auto x : v){
            char c = x.first;
            int f = x.second;
            string curr(f, c);
            ans += curr;
        }
        return ans;
    }
};