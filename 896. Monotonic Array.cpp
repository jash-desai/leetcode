class Solution {
public:
    bool isMonotonic(vector<int>&v) {
        int n = v.size(), f = 0;
        for(int i=1; i<n; i++){
            if(!f and v[i]<v[i-1]) f = -1;
            else if(!f and v[i] > v[i-1]) f = 1;
            else if(f!=0){
                if(f==-1 and v[i]>v[i-1]) return false;
                if(f==1 and v[i]<v[i-1]) return false;
            }
        }
        return true;
    }
};