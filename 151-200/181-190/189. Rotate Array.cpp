class Solution {
public:
    void rotate(vector<int>& v, int k) {
        vector<int> t = v;
        for(int i=0; i<v.size(); i++) v[(i+k)%v.size()] = t[i];
    }
};