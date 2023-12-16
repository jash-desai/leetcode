class Solution {
public:
    void moveZeroes(vector<int>&v) {
        int i = 0, j = 0;
        while(j<size(v)){
            if(v[j]!=0){
                swap(v[i], v[j]);
                i++;
            }
            j++;
        }
        return;
    }
};