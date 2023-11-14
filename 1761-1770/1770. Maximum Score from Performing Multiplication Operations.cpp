class Solution {
public:
    int helperTabOp(vector<int>& nums, vector<int>& multipliers){
        int n=nums.size();
        int m=multipliers.size();
        //Storing results for i+1th index in next
        vector<int> next(m+1,0);
        //Storing results for ith index in next
        vector<int> curr(m+1,0);
        for(int i=m-1;i>=0;i--){
            for(int st=i;st>=0;st--){
                int l=next[st+1]+(multipliers[i]*nums[st]);
                int r=next[st]+(multipliers[i]*nums[n-(i-st)-1]);                
                curr[st]=max(l,r);
            }
            next=curr;
        }
        return curr[0];   
    }    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return helperTabOp(nums,multipliers);
    }
};