class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int cnt=0;
        for(auto c:nums)if(c%2==0)cnt+=c;
        for(auto c:queries)
        {
            int id=c[1],val=c[0];
            if(nums[id]%2==0)cnt-=nums[id];
            nums[id]+=val;
            if(nums[id]%2==0)cnt+=nums[id];
            ans.push_back(cnt);
        }
        return ans;
    }
};