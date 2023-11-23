class Solution {
public:
    vector<int> getConcatenation(vector<int>&v) {
        vector<int> a;
        int n=v.size();
        for(int i=0; i<n; i++){
            a.push_back(v[i]);
        }
        for(int i=0; i<n; i++){
            a.push_back(v[i]);
        }
        return a;
    }
};