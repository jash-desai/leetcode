class Solution {
public:
    int numRescueBoats(vector<int> &v, int k){
        int n = v.size();
        int a=0;
        sort(v.begin(), v.end());
        int i=0, j=n-1;
        int c=0;
        while(i<=j){
            c = v[i]+v[j];
            if(c<=k){
                // a++;
                i++, j--;
            }else{
                // a++;
                j--;
            }
            a++;
        }
        return a;
    }
};