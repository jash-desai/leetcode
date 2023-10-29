class Solution {
public:
    int maxArea(vector<int>&v) {
        int n=v.size();
        int i=0, j=n-1;
        int a=INT_MIN;
        int c=0;
        while(i<j){
            c = (j-i)*(min(v[i],v[j]));
            a = max(a,c);
            if(v[i]<v[j]){
                i++;
            }else{
                j--;
            }
        }
        return a;
    }
};