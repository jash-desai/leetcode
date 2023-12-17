class Solution {
public:
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            int lb=0,ub=nums2.size()-1,mid=0;
            while(lb<=ub && nums2.size()!=0)
            {
                mid=(ub+lb)/2;
                if(nums2[mid]==nums1[i])
                {
                    ans.push_back(nums2[mid]);
                    nums2.erase(nums2.begin()+mid);
                    break;
                }
                else if(nums2[mid]<nums1[i])
                    lb=mid+1;
                else
                    ub=mid-1;
            }
        }
        return ans;
    }
};