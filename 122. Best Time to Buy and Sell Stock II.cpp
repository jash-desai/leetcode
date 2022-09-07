class Solution {
public:
    int maxProfit(vector<int>& v) {
        int a=0; int curr=0;
        curr=v[0];
        for(int i=0; i<v.size(); i++){
            if(v[i]>curr){
                a+= v[i]-curr;
            }
            curr = v[i];
        }
        return a;
    }
};