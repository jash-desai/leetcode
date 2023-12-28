class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int k = v.size();
        if (n==0) {
            return 1;
        }
        for(int i=0; i<k; i++) {
            if(v[i]==0 and (i==0 or v[i-1]==0) and (i==k-1 or v[i+1]==0)){
                v[i] = 1;
                n--;
                if (n==0) {
                    return 1;
                }
            }
        }
        return 0;
    }
};