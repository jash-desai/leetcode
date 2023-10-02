class Solution {
public:
    vector<int> sortArrayByParity(vector<int>&v) {
        int n = v.size(), i = 0, j = 0;
        while(j<n){
            if(!(v[j]&1)) swap(v[i++], v[j++]);
            else j++;
        }
        return v;
    }
};