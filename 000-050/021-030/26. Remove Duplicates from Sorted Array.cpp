class Solution {
public:
    int removeDuplicates(vector<int>&v){
        map<int,int> m;
        vector<int> t;
        for(auto x:v){
            m[x]++;
            if(m[x]<=1) t.push_back(x);
        }
        v=t;
        return t.size();
    }
};