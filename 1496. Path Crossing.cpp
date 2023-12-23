#define py cout << "YES"
#define pn cout << "NO"
class Solution {
public:
    bool isPathCrossing(string s) {
        set<array<int, 2>> st;
        int r = 0, c = 0;
        st.insert({r,c});
        for(char &ch : s){
            if(ch=='N'){
                r--;
                if(st.count({r,c})){
                    py;
                    return 1;
                }else st.insert({r,c});
            }else if(ch=='E'){
                c++;
                if(st.count({r,c})){
                    py;
                    return 1;
                }else st.insert({r,c});
            }else if(ch=='S'){
                r++;
                if(st.count({r,c})){
                    py;
                    return 1;
                }else st.insert({r,c});
            }else{
                c--;
                if(st.count({r,c})){
                    py;
                    return 1;
                }else st.insert({r,c});
            }
        }
        pn;
        return 0;
    }
};