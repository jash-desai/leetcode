class Solution {
public:
    string mergeAlternately(string a, string b) {
        string s;
        int i=0, j=0;
        while(i<a.size() && j<b.size()){
            s.push_back(a[i++]);
            s.push_back(b[j++]);
        }
        while(i<a.size()){
            s.push_back(a[i++]);
        }
        while(j<b.size()){
            s.push_back(b[j++]);
        }

        return s;
    }
};