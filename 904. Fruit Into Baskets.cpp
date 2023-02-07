class Solution {
public:
    int totalFruit(vector<int>& v) {
        int l=-1, sl=-1;
        int lc=0, curr=0;
        int ans=0;
        for(int x:v){
            if(x==l or x==sl){
                curr++;
            }else{
                curr = lc+1;
            }
            if(x==l){
                lc++;
            }else{
                lc=1;
            }
            if(x!=l){
                sl = l;
                l=x;
            }
            ans = max(curr,ans);
        }
        return ans;
    }
};