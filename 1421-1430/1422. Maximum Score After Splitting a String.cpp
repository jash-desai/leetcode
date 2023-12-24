class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ans = 0;
        int zero = 0, one = 0;
        for(auto &c : s){
            if(c=='0') zero++;
            else one++;
        }
        int currZero = 0, currOne = 0;
        for(int i=1; i<n; i++){
            if(s[i-1]=='0'){
                currZero++;
                zero--;
            }else{
                currOne++;
                one--;
            }
            ans = max(ans, currZero + one);
        }
        return ans;
    }
};