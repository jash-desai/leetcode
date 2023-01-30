class Solution {
public:
    int findMinDifference(vector<string> &v) {
        vector<bool> mins(1440);
        for(string t : v) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3));
            
            if(mins[h * 60 + m]) return 0;
            mins[h * 60 + m] = 1;
        }
        int ans = 1e9, pre = -1, e = -1e9, fs=0;
        for(int i=0; i<mins.size(); i++) {
            if(mins[i]) {
                if(pre == -1){
                    pre = i;
                    fs=i;
                }    
                else{
                    ans = min(ans, min(i-pre, 1440-i+pre));
                    pre=i;
                }
                
            }
        }
        return min(ans, min(pre-fs, 1440-pre+fs));
    }
};