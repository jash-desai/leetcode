class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        /*
        // Two Pointer Approach :
        int n = v.size(), m = v[0].size(), i{0}, j{m-1};
        while(i<n and j>=0){
            if(v[i][j] == k) return true;
            else if(v[i][j] > k) j--;
            else i++;
        } return false;
        */

        // Binary search Approach :
        int n = v.size(), m = v[0].size(), l{0}, r={(n*m)-1};
        while(l<=r){
            int mid = l + ((r-l) >> 1);
            int row = mid/m, col = mid%m;
            if(v[row][col] == k) return true;
            else if(v[row][col] < k) l = mid+1;
            else r = mid-1;
        } return false;
    }
};