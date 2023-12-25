class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0, ans2 = 0;
    int n = s.size(); bool f = 1;
    string s1 = string(n, '1');
    string s2 = string(n, '0');
    for(int i=1; i<n; i++){
        s1[i] = (f ? '0' : '1');
        s2[i] = (f ? '1' : '0');
        f = !f;
    }
    for(int i=0; i<n; i++){
        ans1 += (s[i] == s1[i]);
        ans2 += (s[i] == s2[i]);
    }
        return min(ans1, ans2);
    }
};