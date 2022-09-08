class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergedArr(n+m, 0);
        int st1 = 0; int st2 = 0;
        int mainptr = 0;
        while(st1<m && st2<n){
            if(nums1[st1] < nums2[st2]){
                mergedArr[mainptr] = nums1[st1];
                mainptr++;
                st1++;
            }
            else {
                mergedArr[mainptr] = nums2[st2];
                mainptr++;
                st2++;
            }
        }
        while(st1 < m){
            mergedArr[mainptr] = nums1[st1];
            mainptr++;
            st1++;
        }
        while(st2 < n){
            mergedArr[mainptr] = nums2[st2];
            mainptr++;
            st2++;
        }
        for(int i=0; i<mergedArr.size(); i++){
            nums1[i] = mergedArr[i];
        }
    }
};