class Solution {
public:
    int romanToInt(string s){
        map<char,int> m;
        m.insert({'I',1}); m.insert({'V',5}); m.insert({'X',10});
        m.insert({'L',50}); m.insert({'C',100}); m.insert({'D',500}); m.insert({'M',1000});

        int n = s.size();
        int result=0;
        int i=0;
        while(i < n){
            if(m[s[i]] < m[s[i+1]]){
                result += m[s[i+1]] - m[s[i]];
                i++;
            }else{
                result += m[s[i]];
            }
            i++;
        }
        return result;
    }
};