class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        /* Naive : O(N)
        for(int i{0}; i<size(v)-1; i++) if(v[i]>v[i+1]) return i;
        return -1;
        */
        int l = 1, r = size(v) - 2, m;
        while(l<=r){
            m = (l + ((r-l) >> 1));
            if(v[m-1]<v[m] and v[m+1]<v[m]) return m;
            if(v[m-1]<=v[m]) l = m+1;
            else r = m-1;
        }
        return -1;
    }    
};

