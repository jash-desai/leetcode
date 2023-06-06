class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>&v) {
        sort(v.begin(), v.end());
        int i=2; int d = v[1]-v[0];
        while(i<v.size()){
            if(v[i]-v[i-1] != d) return 0;
            i++;
        }
        return 1;
    }
};