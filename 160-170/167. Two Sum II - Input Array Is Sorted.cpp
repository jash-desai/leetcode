class Solution {
public:
    vector<int> twoSum(vector<int>&v, int k) {
        int n=v.size();
        vector<int> a;
        int i=0; int j=n-1;
        int sum=0;
        while(i<j && j>=0){
            sum=v[i]+v[j];
            if(sum==k){
                a.push_back(i+1);
                a.push_back(j+1);
                break;
            }else if(sum<k){
                i++;
            }else if(sum>k){
                j--;
            }
        }
        return a;
    }
};