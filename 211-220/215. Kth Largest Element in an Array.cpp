class Solution {
public:
    int findKthLargest(vector<int>&v, int k) {
        multiset<int> m;
        for(int x:v){
            m.insert(x);
        }
        multiset<int>::iterator it = m.end();
        // --k;
        while(k--){
            --it;
        }
        return (*it);
    }
};