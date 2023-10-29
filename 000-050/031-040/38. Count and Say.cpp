class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = countAndSay(n-1);
        int i = 0;
        string str;
        while(i < s.size()){
            int j = i;

            while(s[i] == s[j]){
                j++;
                if(j == s.size()) break;
            }
            str+= to_string(j-i) + s[i];
            i=j;
        }

        return str;

    }
};