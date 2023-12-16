#define tostr(x) to_string(x)
#define pb push_back
class Solution {
public:
    vector<string> summaryRanges(vector<int>&v) {
        int n=v.size(); 
        if(!n) return {};
        vector<string> a;
        string s = tostr(v[0]);
        int i=1, j=0;
        while(i<n){
            if(v[i] == v[i-1]+1){
                i++;
            }else{
                if(i-1!=j){
                    s += "->";
                    s += tostr(v[i-1]);
                }
                a.pb(s);
                s = tostr(v[i]);
                j=i; i++;
            }
        }
        if(i-1!=j){
            s += "->";
            s += tostr(v[i-1]);
        }
        a.pb(s);
        return a;
    }
};