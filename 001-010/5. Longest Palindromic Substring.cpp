// brute force -->

// class Solution {
// public:
//     void printSubStr(string str, int low, int high){
//         for(int i = low; i <= high; ++i){
//             cout << str[i];
//         }
//     }
//     string longestPalindrome(string str) {
//         string a;
//         int n=str.size();
//         int maxLength = 1, start = 0;
//         for (int i = 0; i < str.length(); i++) {
//             for (int j = i; j < str.length(); j++) {
//                 int flag = 1;
     
//                 // Check palindrome
//                 for (int k = 0; k < (j - i + 1) / 2; k++){
//                     if (str[i + k] != str[j - k]) flag = 0;
//                 }
     
//                 // Palindrome
//                 if (flag && (j - i + 1) > maxLength) {
//                     start = i;
//                     maxLength = j - i + 1;
//                 }
//             }
//         }
        
//         a = str.substr(start, start+maxLength);
//         return a;
//     }
// };


// dp -->
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        // int count=0;
        string a;
        int maxl=0;
        // int l=INT_MAX;
        // int r=INT_MIN;
        for(int d=0; d<n; d++){
            for(int i=0,j=d; j<n; i++,j++){
                if(d==0){
                    dp[i][j]=1;
                }else if(d==1){
                    dp[i][j] = (s[i]==s[j]) ? 2:0;
                }else{
                    if(s[i]==s[j] and dp[i+1][j-1]){
                        dp[i][j] = 2+dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){
                   if(j-i+1 > maxl){
                       maxl = j-i+1;
                       a = s.substr(i,maxl);
                   }
                }
            }
        }
        return a;
        
    }
};