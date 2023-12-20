class Solution {
public:
    int buyChoco(vector<int>& v, int k) {
        sort(v.begin(), end(v));
        if(v[0]+v[1] <= k) return (k-v[0]-v[1]);
        else return k;
    }
};