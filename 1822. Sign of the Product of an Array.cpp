class Solution {
public:
    int arraySign(vector<int>& v) {
        int a=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]==0) return 0;
            if(v[i]<0) a++;
        }
        return (a%2) ? -1:1;
    }
};