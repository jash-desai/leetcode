class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // string ans;
        // for(char c : s){
        //     if(c>='a' and c<='z'){
        //         ans += c;
        //         if(ans.size() > k) return string(1, ans[k]); 
        //     }
        //     else{
        //         int d = c - '0' - 1;
        //         string t = ans;
        //         while(d--){
        //             ans += t;
        //             if(ans.size() > k) return string(1, ans[k]);
        //         }
        //     }
        //     if(ans.size() > k) return string(1, ans[k]);
        // }
        // if(ans.size() > k) return string(1, ans[k]);
        // return "NA";
        long long length = 0; 
        int i = 0;
        
        while (length < k) {
            if (isdigit(s[i])) {
                length *= s[i] - '0';
            } else {
                length++;
            }
            i++;
        }
        
        for (int j = i - 1; j >= 0; j--) {
            if (isdigit(s[j])) {
                length /= s[j] - '0';
                k %= length;
            } else {
                if (k == 0 || k == length) {
                    return std::string(1, s[j]);
                }
                length--;
            }
        }
        
        return "";
    }
};