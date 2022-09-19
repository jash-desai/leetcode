class Solution {
public:
    int trap(vector<int>& height){
        int n = height.size();
        vector<int> left (n);
        left[0] = height[0];
        int heighted_Left = height[0];
        for (int i = 1 ; i < n ; ++i){
            if(heighted_Left < height[i]){
                left[i] = height[i];
                heighted_Left = height[i];
            }else{
                left[i] = heighted_Left;
            }
        }
        int water_trapped = 0;
        int heighted_right = height[n-1];
        for (int i = n-1 ; i >= 0 ; --i){
            water_trapped = water_trapped + max(min(left[i] , heighted_right) - height[i] , 0);
            heighted_right = max(heighted_right , height[i]);
        }
        return water_trapped;
    }
};