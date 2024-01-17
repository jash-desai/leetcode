class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
        map<int, int> mp;
        for(int x : v) mp[x]++;
        set<int> st;
        for(auto &[a,b] : mp){
            if(st.count(b)) return 0;
            st.insert(b);
        }
        return 1;
    }
};