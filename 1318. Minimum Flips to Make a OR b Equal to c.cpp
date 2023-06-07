class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0; i<32; i++){
            bool ai=0, bi=0, ci=0;
            if((a & (1<<i)) != 0) ai=1;
            if((b & (1<<i)) != 0) bi=1;
            if((c & (1<<i)) != 0) ci=1;
            if(!ci){
                if(ai and bi) ans+=2;
                else if(ai or bi) ans++;
            }else{
                if(!ai and !bi) ans++;
            }
        }
        return ans;
    }
};