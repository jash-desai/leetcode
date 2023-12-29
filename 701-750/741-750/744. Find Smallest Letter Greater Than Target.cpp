class Solution {
public:
    char nextGreatestLetter(vector<char>&v, char k) {
        if(v[v.size()-1]<=k) return v[0];
        int l=0, r = v.size()-1, m;
        while(l<=r){
            m = (l+r)>>1;
            if(v[m]<k) l=m+1;
            else r=m-1;
        }
        if(v[l]==k) while(v[l]==k) l++;
        return v[l];
    }
};