class Solution {
public:
    bool check(vector<int>& v) {
        int n = v.size();
        bool rotated = false;
        for(int i = 0; i<n; i++){
            if(v[i] > v[(i+1)%n]){
                if(rotated) return false;
                rotated = true;
            }
            else if(v[i] == v[(i+1)%n]) continue;
        }
        return true;
    }
};