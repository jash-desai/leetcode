class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int n = size(v), m = size(v[0]);
        // /* two pointers approach - 
        int i = 0, j = m-1;
        while(i<n and j>=0){
            if(v[i][j]==k) return 1;
            else if(v[i][j] < k) i++;
            else j--;
        } return 0;
        // */
        /* binary search approach - can't apply here!
        elemnts when seen as imaginary 1d vector won't turn out to be sorted
        int l = 0, r = (n*m)-1, mid;
        while(l<=r){
            mid = l + ((r-l) >>1);
            int i = mid/m, j = mid%m;
            if(v[i][j] == k) return 1;
            else if(v[i][j] < k) l = mid+1;
            else r = mid-1;
        } return 0;
        */
    }
};