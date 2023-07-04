// freq map approach.
class Solution {
public:
    int singleNumber(vector<int>& v) {
        map<int,int> m;
        for(int x:v) m[x]++;
        for(auto x:m){
            if(x.second == 1) return x.first;
        }
        return -1;
    }
};

// XOR approach
class Solution {
public:
    int singleNumber(vector<int>& v) {
        int x=0;
        for(int a:v){
            x ^= a;
        }
        return x;
    }
};