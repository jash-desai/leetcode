class Solution {
public:
    int largestAltitude(vector<int> &v) {
        int a=0;
        int s=0;
        for(int x:v){
            s += x;
            a = max(a,s);
        }
        return a;
    }
};