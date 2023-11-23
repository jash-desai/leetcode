class Solution {
private:
    bool fxn(vector<int>& v, int m, double k){
        double cnt = 0;
        for(int i{0}; i<size(v); i++){
            int x = v[i];
            if(i!=size(v)-1){
                if(!(x%m)) cnt += (x/m);
                else cnt += (x/m) + 1;
            }else cnt += ((double)x/(double)m);
            if(cnt>k) return false;
        }
        return (cnt<=k);
    }
public:
    int minSpeedOnTime(vector<int>& v, double k) {
        int n = size(v); int l{1}, m, ans = -1;
        int r = 1e8;
        while(l<=r){
            m = (l + ((r-l) >> 1));
            if(fxn(v,m,k)){
                ans = m;
                r = m-1;
            }else l = m+1;
        }
        return ans;
    }
};