class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int sum=neededTime[0];
        int mx=neededTime[0];
        
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                sum+=neededTime[i];
                mx=max(mx,neededTime[i]);
            }else{
                ans+=sum-mx;
                sum=neededTime[i];
                mx=neededTime[i];
            }
        }
        return ans+sum-mx;
    }
};