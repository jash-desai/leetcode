class Solution {
public:
    bool canConstruct(string a, string b) {
        int na=a.size(); int nb=b.size();
        map<char,int> m;
        for(int i=0; i<nb; i++){
            m[b[i]]++;
        }
        for(int i=0; i<na; i++){
            if(m[a[i]] <=0) return 0;
            m[a[i]]--;
        }
        return 1;
    }
};