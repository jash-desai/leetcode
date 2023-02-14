class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int i=0;
        int n=a.size(); int m=b.size();
        if(n>m){
            swap(a,b);
            swap(n,m);
        }
        bool carry=0;
        while(i<n){
            if(a[i]=='0' and b[i]=='0'){
                ans += carry ? '1':'0';
                carry = 0;
            }else if(a[i]=='0' and b[i]=='1' or b[i]=='0' and a[i]=='1'){
                ans += carry ? '0':'1';
            }else if(a[i]=='1' and b[i]=='1'){
                ans += carry ? '1' : '0';
                if(!carry) carry=1;
            }
            i++;
        }
        while(i<m){
            if(b[i]=='0' and !carry){
                ans += '0';
            }else if(b[i]=='0' and carry){
                ans += '1';
                carry = 0;
            }else if(b[i]=='1' and !carry){
                ans += '1';
            }else if(b[i]=='1' and carry){
                ans += '0';
                carry = 1;
            }
            i++;
        }
        if(carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};