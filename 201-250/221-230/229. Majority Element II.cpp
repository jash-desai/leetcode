class Solution {
public:
    vector<int> majorityElement(vector<int>&v) {
        int n = v.size(), cnta = 0, cntb = 0, a, b;
        for(int x:v){
            if(x==a) cnta++;
            else if(x==b) cntb++;
            else if(!cnta) a = x, cnta++;
            else if(!cntb) b = x, cntb++;
            else cnta--, cntb--;
        }
        cnta = 0, cntb = 0;
        for(int x : v){
            if(x==a) cnta++;
            else if(x==b) cntb++;
        }
        vector<int> ans;
        if(cnta > n/3) ans.push_back(a);
        if(cntb > n/3) ans.push_back(b);
        return ans;
    }
};