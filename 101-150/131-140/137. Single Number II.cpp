class Solution {
public:
    int singleNumber(vector<int>& v) {
        vector<int> sum(32); int res = 0;
        for(int x: v){
            for (int i=0; i<32; i++) {
                bool ith = x & (1<<i);
                if(ith) sum[i]++;
            }
        }
        for(int i=0; i<32; i++) {
            res += (sum[i]%3) * (1<<i);
        }
        return res;
    }
};