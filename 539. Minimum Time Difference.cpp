class Solution {
public:
    int findMinDifference(vector<string> &v) {
        vector<int> mins(1440);
        for(string t : v) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3));
            
            if(mins[h * 60 + m]) return 0;
            mins[h * 60 + m] = 1;
        }
        int ans = 1e9, pre = -1, s = 1e9, e = -1e9;
        for(int i=0; i<mins.size(); i++) {
            if(mins[i]) {
                if(pre == -1) pre = i;
                else ans = min(ans, i - pre), pre = i;
                s = min(s, i);
                e = max(e, i);
            }
        }
        return min(ans, 1440 - (e - s));
    }
};