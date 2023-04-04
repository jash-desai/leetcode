class Solution {
public:
    /* recursive funtion :
    void rec(string &s, int&k, int i, map<char,bool>&m){
        if(i==s.size()){
            return;
        }
        if(m.count(s[i])){
            k++;
            m.clear();
            m[s[i]]=1;
            rec(s,k,i+1,m);
        }else{
            m[s[i]]=1;
            rec(s,k,i+1,m);
        }
    }
    */
    int partitionString(string s) {
        /* recursive call :
         int a=1;
         map<char,bool> m;
         rec(s,a,0,m);
         return a;
        */
        // int i = 0, ans = 1,flag = 0;
        // while(i < s.size()){
        //     int val = s[i] - 'a';
        //     if(flag & (1<<val)) {
        //         flag = 0;
        //         ans++;
        //     }
        //     flag = flag | (1<<val);
        //     i++;
        // }
        // return ans;
        unordered_set<char> st;
        int ans=1;
        for(int i=0; i<s.size(); i++){
            if(st.find(s[i])!=st.end()){
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return ans;
    }
};