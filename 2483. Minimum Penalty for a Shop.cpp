class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size(); vector<int> pre(n+1, 0), pos(n+1, 0);
        pre[0] = (s[0]=='N'); 
        for(int i=1; i<n; i++){
            if(s[i]=='N') pre[i] = pre[i-1]+1;
            else pre[i] = pre[i-1];
        } pre[n] = pre[n-1];
        for(int i=n-1; i>=0; i--){
            if(s[i]=='Y') pos[i] = pos[i+1]+1;
            else pos[i] = pos[i+1];
        } int ans = pos[0], ansi = 0;
        for(int i=1; i<=n; i++){
            int curr = pre[i-1] + pos[i];
            if(curr<ans){
                ans = curr;
                ansi = i;
            }
        }
        return ansi;
    }
};