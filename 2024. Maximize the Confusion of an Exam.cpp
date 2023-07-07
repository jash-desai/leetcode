class Solution {
private:
    int maxW(string s, int n, char c, int k) {
        int ans = 0, flip = 0, l = 0;
        for(int r = 0; r < n; r++){
            flip += (s[r] != c);
            if(flip > k){
                while(s[l] == c) l++;
                l++; flip--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = size(s), ans = 0, cnt = 0, l = 0;
        // return max(maxW(s,n,'T',k), maxW(s,n,'F',k));
        for(int r=0; r<n; r++){
            cnt += (s[r]!='T');
            if(cnt>k){
                while(s[l] == 'T') l++;
                l++; cnt--;
            }
            ans = max(ans, r-l+1);
        }
        l = 0, cnt = 0;
        for(int r=0; r<n; r++){
            cnt += (s[r]!='F');
            if(cnt>k){
                while(s[l] == 'F') l++;
                l++; cnt--;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};