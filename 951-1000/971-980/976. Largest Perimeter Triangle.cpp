class Solution {
public:
    int largestPerimeter(vector<int>&a) {
        sort(a.begin(), a.end(), greater<int>());
        for(int i=2; i<a.size(); i++){
            if(a[i-2] < a[i-1]+a[i]) return a[i-2]+a[i-1]+a[i];
        }
        return 0;
    }
};