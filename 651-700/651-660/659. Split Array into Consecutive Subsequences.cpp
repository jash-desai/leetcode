class Solution {
public:
    bool isPossible(vector<int>& v) {
        int n=v.size();
        map<int,int> fm;
        map<int,int> hm;
        for(int x:v){
            fm[x]++;
        }
        for(int x:v){
            if(fm[x]==0){
                continue;
            }
            if(hm[x]>0){
                hm[x]--;
                hm[x+1]++;
                fm[x]--;
            }
            else if(fm[x]>0 and fm[x+1]>0 and fm[x+2]>0){
                fm[x]--; fm[x+1]--; fm[x+2]--;
                hm[x+3]++;
            }else{
                return false;
            }
        }
        return true;
    }
};